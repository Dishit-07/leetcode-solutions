struct SegmentTreeNode {
    int prod;
    vector<int> count; // count[r] = number of prefixes in this segment having product % k == r
    
    SegmentTreeNode(int k = 1) {
        prod = 1;
        count.assign(k, 0);
    }
};
class Solution {
    int K;
    vector<SegmentTreeNode> tree;

    void merge(SegmentTreeNode& node, const SegmentTreeNode& left, const SegmentTreeNode& right) {
        node.prod = (1LL * left.prod * right.prod) % K;
        
        // Copy left counts
        for (int r = 0; r < K; r++) {
            node.count[r] = left.count[r];
        }
        
        // Shift right counts by left.prod and add
        for (int r = 0; r < K; r++) {
            if (right.count[r] > 0) {
                int new_r = (1LL * left.prod * r) % K;
                node.count[new_r] += right.count[r];
            }
        }
    }
    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % K;
            tree[node].prod = val;
            tree[node].count[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int mod_val = val % K;
            tree[node].prod = mod_val;
            fill(tree[node].count.begin(), tree[node].count.end(), 0);
            tree[node].count[mod_val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }SegmentTreeNode queryRange(int node, int start, int end, int L, int R) {
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (R <= mid) {
            return queryRange(2 * node, start, mid, L, R);
        }
        if (L > mid) {
            return queryRange(2 * node + 1, mid + 1, end, L, R);
        }
        
        SegmentTreeNode left = queryRange(2 * node, start, mid, L, R);
        SegmentTreeNode right = queryRange(2 * node + 1, mid + 1, end, L, R);
        SegmentTreeNode res(K);
        merge(res, left, right);
        return res;
    }
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        this->K = k;
        tree.assign(4 * n, SegmentTreeNode(k));

        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start_i = q[2];
            int target_x = q[3];

            // Step 1: Persistent Point Update
            update(1, 0, n - 1, idx, val);

            // Step 2: Query Range [start_i, n - 1]
            SegmentTreeNode query_res = queryRange(1, 0, n - 1, start_i, n - 1);

            // Step 3: Extract count of prefixes with product % k == target_x
            result.push_back(query_res.count[target_x]);
        }

        return result;
    }
};
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canFinish(piles, mid, h))
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }

private:
    bool canFinish(vector<int>& piles, int speed, int h) {
        long long time = 0;

        for (int pile : piles) {
            time += (pile + speed - 1) / speed;

            if (time > h)
                return false;
        }

        return true;
    }
};
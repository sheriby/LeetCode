#include <bits/stdc++.h>
using namespace std;

struct BigInt {
    vector<int> nums;
    BigInt(string in, bool re = true) {
        int len = in.size();
        nums.resize(len);
        if (re) reverse(in.begin(), in.end());
        for (int i = 0; i < len; ++i) nums[i] = in[i] - '0';
    }

    BigInt(vector<int> nums) : nums(nums) {}
    // 字符串的乘法
    BigInt operator*(const BigInt& ans) {
        vector<int> a = this->nums, b = ans.nums;
        int lena = a.size(), lenb = b.size();
        int max_len = lena + lenb;
        vector<int> res(max_len, 0);
        for (int i = 0; i < lena; ++i) {
            for (int j = 0; j < lenb; ++j) res[i + j] += a[i] * b[j];
        }
        for (int i = 1; i < max_len; ++i) {
            res[i] += res[i - 1] / 10;
            res[i - 1] %= 10;
        }

        int i;
        for (i = max_len - 1; i > 0; --i) {
            if (res[i] != 0) break;
        }
        res.resize(i + 1);
        return BigInt(res);
    }

    // 字符串的幂
    BigInt operator^(int a) {
        BigInt cur = *this;
        BigInt res("1");
        while (a) {
            if (a & 1) res = res * cur;
            cur = cur * cur;
            a >>= 1;
        }
        return res;
    }

    int toint() {
        int res = 0;
        for (int i = this->nums.size() - 1; i >= 0; --i) {
            res *= 10;
            res += this->nums[i];
        }
        return res;
    }

    int toll() {
        long long res = 0;
        for (int i = this->nums.size() - 1; i >= 0; --i) {
            res *= 10;
            res += this->nums[i];
        }
        return res;
    }

    // 字符串的加法
    BigInt operator+(const BigInt& ans) {
        vector<int> a = this->nums, b = ans.nums;
        int lena = a.size(), lenb = b.size();
        int max_len = max(lena, lenb) + 1;
        vector<int> res(max_len, 0);
        int jw = 0, sum = 0;
        for (int i = 0; i < max_len; ++i) {
            int numa = 0, numb = 0;
            if (i < lena) numa += a[i];
            if (i < lenb) numb += b[i];
            sum = numa + numb + jw;
            jw = sum / 10;
            res[i] = sum % 10;
        }
        int i;
        for (i = max_len - 1; i > 0; --i) {
            if (res[i] != 0) break;
        }
        res.resize(i + 1);
        return BigInt(res);
    }

    friend ostream& operator<<(ostream& output, const BigInt& bigint) {
        vector<int> nums = bigint.nums;
        int len = nums.size();
        for (int i = len - 1; i >= 0; --i) {
            output << nums[i];
        }
        return output;
    }
};

int main(int argc, char const* argv[]) {
    // BigInt a("12343123281041418202156"), b("2280328301238120483344");
    BigInt a("1234567"), b("123");
    BigInt c = a + b;
    BigInt d = b * a;
    BigInt e = a ^ b.toint();
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    return 0;
}

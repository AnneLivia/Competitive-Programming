#include <iostream>
#include <vector>

using namespace std;

vector<int>v;

class Bit {
private:
    vector<int>bit;
    int sz;
public:
    void build(int sz) {
        this->bit.assign(sz + 1, 0);
        this->sz = sz;
        // in this problem each position starts with 0 (we must count the frequency of each number)
        for (int i = 0; i < this->sz; i++) {
            this->bit[i] = 0;
        }
    }

    void clear_bit() {
        bit.clear();
        this->sz = 0;
    }

    int sum(int index) {
        int sum = 0;
        while(index > 0) {
            sum+=bit[index];
            index-=index&(-index);
        }
        return sum;
    }

    void update(int index, int value) {
        while(index < this->sz) {
            this->bit[index]+=value;
            index+=index&(-index);
        }
    }

    int inversion_sum() {
        // since in the sum it goes backwards (index -= index & -index)
        // if a number smaller than other comes after, it's number is going to be updated
        // then, if it does not return 0, one smaller number comes after another number

        int cont = 0;
        for (int i = (int)v.size() - 1; i >= 0; i--) {
            cont+=this->sum(v[i]);
            this->update(v[i], 1);
        }

        return cont;
    }
};

int main()
{
    int n, maximum;
    Bit b;
    while(cin >> n && n) {
        b.clear_bit();
        v.assign(n, 0);
        maximum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] > maximum)
                maximum = v[i];
        }
        b.build(maximum + 1);

        if((b.inversion_sum() & 1) == 0) {
            cout << "Carlos\n";
        } else {
            cout << "Marcelo\n";
        }
    }
    return 0;
}

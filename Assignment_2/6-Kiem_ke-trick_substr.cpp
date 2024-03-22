#include <iostream>
#include <vector>

using namespace std;

class StringName
{
  public:
    string character;
    int size;
};

int compare(const StringName &self, const StringName &other)
{
    if (self.size > other.size)
        return 1;
    if (self.size < other.size)
        return -1;
    unsigned long long self_temp, other_temp;
    int i;
    for (i = 0; i + 17 <= self.size; i += 17)
    {
        self_temp = stoull(self.character.substr(i, 17));
        other_temp = stoull(other.character.substr(i, 17));
        // cout << "track:" << self_temp << " " << other_temp << endl;
        if (self_temp > other_temp)
            return 1;
        if (self_temp < other_temp)
            return -1;
    }
    if (i > self.size - 1)
        return 0;
    self_temp = stoull(self.character.substr(i, self.size - i));
    other_temp = stoull(other.character.substr(i, other.size - i));
    // cout << "track:" << self_temp << " " << other_temp << endl;
    if (self_temp > other_temp)
        return 1;
    if (self_temp < other_temp)
        return -1;
    return 0;
}

class Good
{
  public:
    StringName name;
    long sell;
    Good() : name{0}, sell{1} {};
    Good(const string &inputName, const long &inputSell = 1)
    {
        this->name.character = inputName;
        this->name.size = inputName.size();
        this->sell = inputSell;
    }
};

class Summary
{
  public:
    vector<Good> goods;
    long size;
    Summary()
    {
        size = 0;
    }
};

int SoSanh(const Good &good_1, const Good &good_2)
{
    if (good_1.sell < good_2.sell)
        return 1;
    if (good_1.sell == good_2.sell)
        if (compare(good_2.name, good_1.name) < 0)
            return 1;
    return -1;
}

long partition(vector<Good> &goods, const long &start, const long &end)
{
    Good pivot = goods[start];
    long count = 0;
    for (long i = start + 1; i <= end; ++i)
        if (SoSanh(goods[i], pivot) <= 0)
            ++count;
    long pivotIndex = start + count;
    swap(goods[pivotIndex], goods[start]);
    long i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (SoSanh(goods[i], pivot) <= 0)
            ++i;
        while (SoSanh(goods[j], pivot) > 0)
            --j;
        if (i < pivotIndex && j > pivotIndex)
            swap(goods[i++], goods[j--]);
    }
    return pivotIndex;
}

void XapXep(vector<Good> &goods, const long &start, const long &end)
{
    if (start >= end)
        return;
    long pivot = partition(goods, start, end);
    XapXep(goods, start, pivot - 1);
    XapXep(goods, pivot + 1, end);
}

int main()
{
    long numberOfBill;
    cin >> numberOfBill;
    cin.ignore();
    Summary summary;
    string goodInput;
    bool check = false;
    for (long i = 0; i < numberOfBill; ++i)
    {
        getline(cin, goodInput);
        for (long j = 0; j < summary.size; ++j)
            if (goodInput == summary.goods[j].name.character)
            {
                ++summary.goods[j].sell;
                check = true;
                break;
            }
        if (!check)
        {
            summary.goods.push_back(Good(goodInput));
            ++summary.size;
        }
        else
            check = false;
    }
    XapXep(summary.goods, 0, summary.size - 1);
    for (long i = 0; i < summary.size; ++i)
        cout << summary.goods[i].name.character << " " << summary.goods[i].sell << "\n";
    return 0;
}

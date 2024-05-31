#include <iostream>
#include <string>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
int random(int low, int high)
{
    uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

class Date {
private:
    int day = 0, month = 0, year = 0;
public:
    Date() {
        day = random(1, 31);
        month = random(1, 12);
        year = random(1950, 2023);
    };

    friend ostream& operator << (ostream& stream, const Date& p) {
        stream << p.day << "." << p.month << "." << p.year;
        return stream;
    }
    friend bool operator < (const Date dt1, const Date dt2)
    {
        if (dt1.year < dt2.year)return true;
        else {
            if (dt1.year == dt2.year) {
                if (dt1.month < dt2.month)return true;
                else {
                    if (dt1.month == dt2.month) {
                        return dt1.day < dt2.day;
                    }
                    else return false;
                }
            }
            else return false;
        }
    }
    friend bool operator > (const Date dt1, const Date& dt2)
    {
        if (dt1.year > dt2.year)return true;
        else {
            if (dt1.year == dt2.year) {
                if (dt1.month > dt2.month)return true;
                else {
                    if (dt1.month == dt2.month) {
                        return dt1.day > dt2.day;
                    }
                    else return false;
                }
            }
            else return false;
        }
    }
};

class Person {
private:
    string fullName;
    Date birthDate;
    int brainVolume;
public:


    Person() {
        fullName = creat_str();
        brainVolume = random(1000, 1700);
    }

    Person(const string& name, const Date& date, int volume) : fullName(name), birthDate(date), brainVolume(volume) {}

    string creat_str() {
        string abc = "qazwsxedcrfvtgbyhnujmikolp";
        string new_str = "";
        for (int i = 0; i < 5; i++) {
            new_str += abc[random(0, 25)];
        }
        return new_str;
    }

    void print() {
        cout << fullName << ' ' << birthDate << ' ' << brainVolume << endl;
    }
    string getfullName() {
        return fullName;
    }
    Date getBirthDate() {
        return birthDate;
    }
    int getBrainVolume() {
        return brainVolume;
    }
};

class Container {
private:
    Person* records;
    int count;
    int capacity;

public:
    Container() {
        count = 5;
        records = new Person[count];
    }

    ~Container() {
        delete[] records;
    }

    // Метод для добавления записи в контейнер
    void addRecord(const string& fullName, const Date& birthDate, int brainVolume) {

        Person* new_records = new Person[count + 1];
        for (int i = 0; i < count; i++) {
            new_records[i] = records[i];
        }
        Person newP(fullName, birthDate, brainVolume);
        new_records[count] = newP;
        count++;
        records = new_records;

        cout << "Запись добавлена" << endl;
    }

    void printAllRecords() {
        for (int i = 0; i < count; i++) {
            records[i].print();
        }
    }
    void swap(int i, int j) {
        Person copy = records[i];
        records[i] = records[j];
        records[j] = copy;
    }
    //1 Пузырьковая
    void BubbleSort() {
        int nsravn = 0;
        int nswap = 0;

        int select = 0;
        cout << "Выберите по каким данным сортировать записи" << endl;
        cout << "[1] ФИО." << endl;
        cout << "[2] Дата." << endl;
        cout << "[3] Объем мозга." << endl;
        while (select < 1 || select>3) {
            cin >> select;
        }
        for (int i = 0; i + 1 < count; ++i) {
            for (int j = 0; j + 1 < count - i; ++j) {
                nsravn++;
                if (select == 1) {
                    if (records[j + 1].getfullName() < records[j].getfullName()) {

                        swap(j, j + 1);
                        nswap++;

                    }

                }
                if (select == 2) {
                    if (records[j + 1].getBirthDate() < records[j].getBirthDate())swap(j, j + 1);;
                }
                if (select == 3) {
                    if (records[j + 1].getBrainVolume() < records[j].getBrainVolume())swap(j, j + 1);;
                }
            }
        }
    }

    //2 Вставка
    void InsertionSort() {
        int select = 0;
        cout << "Выберите по каким данным сортировать записи" << endl;
        cout << "[1] ФИО." << endl;
        cout << "[2] Дата." << endl;
        cout << "[3] Объем мозга." << endl;
        while (select < 1 || select>3) {
            cin >> select;
        }
        if (select == 1) {
            for (int i = 1; i < count; i++) {
                string x = records[i].getfullName();
                int j = i;
                while (j > 0 && records[j - 1].getfullName() > x) {
                    records[j] = records[j - 1];
                    --j;
                }
                records[j] = records[i];
            }
        }
        if (select == 2) {
            for (int i = 1; i < count; i++) {
                Date x = records[i].getBirthDate();
                int j = i;
                while (j > 0 && records[j - 1].getBirthDate() > x) {
                    records[j] = records[j - 1];
                    --j;
                }
                records[j] = records[i];
            }
        }
        if (select == 3) {
            for (int i = 1; i < count; ++i) {
                int x = records[i].getBrainVolume();
                int j = i;
                while (j > 0 && records[j - 1].getBrainVolume() > x) {
                    records[j] = records[j - 1];
                    --j;
                }
                records[j] = records[i];
            }
        }
    }

    //3 Шейк
    void ShakerSort() {
        int select = 0;
        cout << "Выберите по каким данным сортировать записи" << endl;
        cout << "[1] ФИО." << endl;
        cout << "[2] Дата." << endl;
        cout << "[3] Объем мозга." << endl;
        while (select < 1 || select>3) {
            cin >> select;
        }
        if (select == 1) {
            int left = 0;
            int right = count - 1;
            while (left <= right) {
                for (int i = right; i > left; --i) {
                    if (records[i - 1].getfullName() > records[i].getfullName()) {
                        swap(i - 1, i);
                    }
                }
                ++left;
                for (int i = left; i < right; ++i) {
                    if (records[i].getfullName() > records[i + 1].getfullName()) {
                        swap(i, i + 1);
                    }
                }
                --right;
            }
        }
        if (select == 2) {
            int left = 0;
            int right = count - 1;
            while (left <= right) {
                for (int i = right; i > left; --i) {
                    if (records[i - 1].getBirthDate() > records[i].getBirthDate()) {
                        swap(i - 1, i);
                    }
                }
                ++left;
                for (int i = left; i < right; ++i) {
                    if (records[i].getBirthDate() > records[i + 1].getBirthDate()) {
                        swap(i, i + 1);
                    }
                }
                --right;
            }
        }
        if (select == 3) {
            int left = 0;
            int right = count - 1;
            while (left <= right) {
                for (int i = right; i > left; --i) {
                    if (records[i - 1].getBrainVolume() > records[i].getBrainVolume()) {
                        swap(i - 1, i);
                    }
                }
                ++left;
                for (int i = left; i < right; ++i) {
                    if (records[i].getfullName() > records[i + 1].getfullName()) {
                        swap(i, i + 1);
                    }
                }
                --right;
            }
        }

    }

    //Расческа
    void combSort() {
        int gap = count;
        float shrink = 1.3;
        bool sorted = false;
        int select = 0;
        cout << "Выберите по каким данным сортировать записи" << endl;
        cout << "[1] ФИО." << endl;
        cout << "[2] Дата." << endl;
        cout << "[3] Объем мозга." << endl;
        while (select < 1 || select>3) {
            cin >> select;
        }
        while (!sorted) {
            gap = (int)(gap / shrink);

            if (gap <= 1) {
                gap = 1;
                sorted = true;
            }

            for (int i = 0; i < count - gap; i++) {
                int j = i + gap;
                if (select == 1) {
                    if (records[i].getfullName() > records[j].getfullName()) {
                        swap(i, j);
                        sorted = false;
                    }
                }
                if (select == 2) {
                    if (records[i].getBirthDate() > records[j].getBirthDate()) {
                        swap(i, j);
                        sorted = false;
                    }
                }
                if (select == 3) {
                    if (records[i].getBrainVolume() > records[j].getBrainVolume()) {
                        swap(i, j);
                        sorted = false;
                    }
                }

            }
        }
    }

    //4 начало быстрой сортировки

    void QuickSortImpl(int select, int l, int r) {
        if (select == 1) {
            if (l < r) {
                string x = records[r].getfullName();
                int less = l;
                for (int i = l; i < r; ++i) {
                    if (records[i].getfullName() <= x) {
                        swap(i, less);
                        ++less;
                    }
                }
                swap(less, r);
                int q = less;
                QuickSortImpl(select, l, q - 1);
                QuickSortImpl(select, q + 1, r);
            }
        }
        if (select == 2) {
            if (l < r) {
                Date x = records[r].getBirthDate();
                int less = l;
                for (int i = l; i < r; ++i) {
                    if (x > records[i].getBirthDate()) {
                        swap(i, less);
                        ++less;
                    }
                }
                swap(less, r);
                int q = less;
                QuickSortImpl(select, l, q - 1);
                QuickSortImpl(select, q + 1, r);
            }
        }
        if (select == 3) {
            if (l < r) {
                int x = records[r].getBrainVolume();
                int less = l;
                for (int i = l; i < r; ++i) {
                    if (records[i].getBrainVolume() <= x) {
                        swap(i, less);
                        ++less;
                    }
                }
                swap(less, r);
                int q = less;
                QuickSortImpl(select, l, q - 1);
                QuickSortImpl(select, q + 1, r);
            }
        }

    }

    void QuickSort(vector<int>& values) {
        if (count > 0) {
            int select = 0;
            cout << "Выберите по каким данным сортировать записи" << endl;
            cout << "[1] ФИО." << endl;
            cout << "[2] Дата." << endl;
            cout << "[3] Объем мозга." << endl;
            while (select < 1 || select>3) {
                cin >> select;
            }
            QuickSortImpl(select, 0, values.size() - 1);
        }

    }
    //Конец быстрой сортировки

    //5 Гномья Сортировка
    void gnomeSort() {
        int select = 0;
        cout << "Выберите по каким данным сортировать записи" << endl;
        cout << "[1] ФИО." << endl;
        cout << "[2] Дата." << endl;
        cout << "[3] Объем мозга." << endl;
        while (select < 1 || select>3) {
            cin >> select;
        }
        if (select == 1) {
            int n = count;
            int index = 0;  while (index < n) {
                if (index == 0)
                    index++;
                if (records[index].getfullName() >= records[index - 1].getfullName())
                    index++;
                else {
                    swap(index, index - 1);
                    index--;
                }
            }
        }
        if (select == 2) {
            int n = count;
            int index = 0;  while (index < n) {
                if (index == 0)
                    index++;
                if (records[index - 1].getBirthDate() < records[index].getBirthDate())
                    index++;
                else {
                    swap(index, index - 1);
                    index--;
                }
            }
        }
        if (select == 3) {
            int n = count;
            int index = 0;  while (index < n) {
                if (index == 0)
                    index++;
                if (records[index].getBrainVolume() >= records[index - 1].getBrainVolume())
                    index++;
                else {
                    swap(index, index - 1);
                    index--;
                }
            }
        }

    }

    //6 Шелл
    void shellSort()
    {
        int select = 0;
        cout << "Выберите по каким данным сортировать записи" << endl;
        cout << "[1] ФИО." << endl;
        cout << "[2] Дата." << endl;
        cout << "[3] Объем мозга." << endl;
        while (select < 1 || select>3) {
            cin >> select;
        }
        if (select == 1) {
            for (int step = count / 2; step > 0; step /= 2)
            {
                for (int i = step; i < count; i += 1)
                {
                    int j = i;
                    while (j >= step && records[j - step].getfullName() > records[i].getfullName())
                    {
                        swap(j, j - step);
                        j -= step;
                    }
                }
            }
        }
        if (select == 2) {
            for (int step = count / 2; step > 0; step /= 2)
            {
                for (int i = step; i < count; i += 1)
                {
                    int j = i;
                    while (j >= step && records[j - step].getBirthDate() > records[i].getBirthDate())
                    {
                        swap(j, j - step);
                        j -= step;
                    }
                }
            }
        }
        if (select == 3) {
            for (int step = count / 2; step > 0; step /= 2)
            {
                for (int i = step; i < count; i += 1)
                {
                    int j = i;
                    while (j >= step && records[j - step].getBrainVolume() > records[i].getBrainVolume())
                    {
                        swap(j, j - step);
                        j -= step;
                    }
                }
            }
        }

    }

    //7 Слияние
    void merge_sort() {
        int select = 0;
        cout << "Выберите по каким данным сортировать записи" << endl;
        cout << "[1] ФИО." << endl;
        cout << "[2] Дата." << endl;
        cout << "[3] Объем мозга." << endl;
        while (select < 1 || select>3) {
            cin >> select;
        }
        mergeSort(records, count, select);
    }

    void mergeSort(Person* data, int lenD, int select)
    {
        if (lenD > 1) {
            int middle = lenD / 2;
            int rem = lenD - middle;
            Person* L = new Person[middle];
            Person* R = new Person[rem];
            for (int i = 0; i < lenD; i++) {
                if (i < middle) {
                    L[i] = data[i];
                }
                else {
                    R[i - middle] = data[i];
                }
            }
            mergeSort(L, middle, select);
            mergeSort(R, rem, select);
            merge(data, lenD, L, middle, R, rem, select);
        }
    }

    void merge(Person* merged, int lenD, Person* L, int lenL, Person* R, int lenR, int select) {
        if (select == 1) {
            int i = 0;
            int j = 0;
            while (i < lenL || j < lenR) {
                if (i < lenL & j < lenR) {
                    if (L[i].getfullName() <= R[j].getfullName()) {
                        merged[i + j] = L[i];
                        i++;
                    }
                    else {
                        merged[i + j] = R[j];
                        j++;
                    }
                }
                else if (i < lenL) {
                    merged[i + j] = L[i];
                    i++;
                }
                else if (j < lenR) {
                    merged[i + j] = R[j];
                    j++;
                }
            }
        }
        if (select == 2) {
            int i = 0;
            int j = 0;
            while (i < lenL || j < lenR) {
                if (i < lenL & j < lenR) {
                    if (!(L[i].getBirthDate() > R[j].getBirthDate())) {
                        merged[i + j] = L[i];
                        i++;
                    }
                    else {
                        merged[i + j] = R[j];
                        j++;
                    }
                }
                else if (i < lenL) {
                    merged[i + j] = L[i];
                    i++;
                }
                else if (j < lenR) {
                    merged[i + j] = R[j];
                    j++;
                }
            }
        }
        if (select == 3) {
            int i = 0;
            int j = 0;
            while (i < lenL || j < lenR) {
                if (i < lenL & j < lenR) {
                    if (L[i].getBrainVolume() <= R[j].getBrainVolume()) {
                        merged[i + j] = L[i];
                        i++;
                    }
                    else {
                        merged[i + j] = R[j];
                        j++;
                    }
                }
                else if (i < lenL) {
                    merged[i + j] = L[i];
                    i++;
                }
                else if (j < lenR) {
                    merged[i + j] = R[j];
                    j++;
                }
            }
        }

    }
    //конец слияния

    //8 начало пирамиды
    void pyramid_sort() {
        int select = 0;
        cout << "Выберите по каким данным сортировать записи" << endl;
        cout << "[1] ФИО." << endl;
        cout << "[2] Дата." << endl;
        cout << "[3] Объем мозга." << endl;
        while (select < 1 || select>3) {
            cin >> select;
        }
        heapSort(records, count, select);
    }

    void heapify(Person* arr, int n, int i, int select) {
        if (select == 1) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[left].getfullName() > arr[largest].getfullName()) {
                largest = left;
            }
            if (right < n && arr[right].getfullName() > arr[largest].getfullName()) {
                largest = right;
            }
            if (largest != i) {
                swap(i, largest);
                heapify(arr, n, largest, select);
            }
        }
        if (select == 2) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[left].getBirthDate() > arr[largest].getBirthDate()) {
                largest = left;
            }
            if (right < n && arr[right].getBirthDate() > arr[largest].getBirthDate()) {
                largest = right;
            }
            if (largest != i) {
                swap(i, largest);
                heapify(arr, n, largest, select);
            }
        }
        if (select == 3) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[left].getBrainVolume() > arr[largest].getBrainVolume()) {
                largest = left;
            }
            if (right < n && arr[right].getBrainVolume() > arr[largest].getBrainVolume()) {
                largest = right;
            }
            if (largest != i) {
                swap(i, largest);
                heapify(arr, n, largest, select);
            }
        }

    }
    void heapSort(Person* arr, int n, int select) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i, select);
        }
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0, select);
        }
    }
    //конец пирамиды
};

int main() {
    setlocale(LC_ALL, "ru");
    Container FI202;
    Date dana;
    FI202.addRecord("Vika", dana, 1700);
    FI202.addRecord("123", dana, 1600);
    FI202.addRecord("321", dana, 1500);
    FI202.printAllRecords();
    FI202.BubbleSort();
    cout << "-------------------------------" << endl;
    FI202.printAllRecords();
    FI202.InsertionSort();
    cout << "-------------------------------" << endl;
    FI202.printAllRecords();
    FI202.combSort();
    cout << "-------------------------------" << endl;
    FI202.printAllRecords();
    FI202.ShakerSort();
    cout << "-------------------------------" << endl;
    FI202.printAllRecords();

    FI202.gnomeSort();
    cout << "-------------------------------" << endl;
    FI202.printAllRecords();
    FI202.shellSort();
    cout << "-------------------------------" << endl;
    FI202.printAllRecords();



    return 0;
}
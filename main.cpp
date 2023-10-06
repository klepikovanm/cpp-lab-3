#include <iostream>
using namespace std;

//Массив с чашками
long int all[32]={};

//Функция, которая принимает n-количество чашек, masha-каша Маши, peter-каша Пети
long int porridge(int n, long int masha, long int peter) {
    //Если чашки заканчиваются, возвращаем абсолютную разницу
    if (n<0) {
        return abs(masha-peter);
    }

    long int p_first;
    long int p_second;
    /*Рассматриваем два случая: отдаем чашку Маше и переходим к следующей,
    отдаем чашку Пете и переходим к следующей.
    Возвращаем минимальный из вариантов*/
    p_first = porridge(n-1, masha+all[n], peter);
    p_second = porridge(n-1, masha, peter+all[n]);

    return min(p_first, p_second);
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        long int m;
        cin >> m;
        all[i] = m; 
    }
    cout << porridge(n-1, 0, 0);
    return 0;
}

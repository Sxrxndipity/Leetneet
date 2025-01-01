int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int n = studentsSize;
    int zero = 0;
    int one = 0;
    for (int i; i < n; i++) {
        if (students[i] == 0) {
            zero++;
        }
        else {
            one++;
        }
    }
    for (int i; i < n; i++) {
        if (sandwiches[i] == 0 && zero > 0) {
            zero--;
        }
        else if (sandwiches[i] == 1 && one > 0){
            one--;
        }
        else {
            return n-i;
        }
    }
    return zero+one;
}

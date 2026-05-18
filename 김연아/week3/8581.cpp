#include iostream
using namespace std;
#include vector
#include string 
#include algorithm 

int main() {
    iossync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin  N;

    vectorlong long A(N), B(N);
    for (int i = 0; i N; i++) cin  A[i];
    for (int i = 0; i N; i++) cin  B[i];

    오름차순 정렬
        sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long result = 0;
    for (int i = 0; i N; i++) {
        result += A[i]  B[i];
    }

    cout  result  n;
    return 0;
}
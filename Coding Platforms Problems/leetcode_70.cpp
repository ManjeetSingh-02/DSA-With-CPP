// Climbing Stairs

if(n <= 1)
    return 1;
int a = 1, b = 1, c = 0;

for(int i = 2 ; i <= n ; i++) {
    c = a + b;
    b = a;
    a = c;
}
return c;
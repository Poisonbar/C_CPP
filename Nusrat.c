#include<stdio.h>
#include<conio.h>
#include<windows.h>
char c;
int modt, n, m, nn, err=0;
void printerr(){
    char err[]="\nWrong input!!!";
    for(int i=0; err[i]!='\0'; ++i) putchar(err[i]), Sleep(10);
}
void outi(int x, char xx){
    int k=nn;
    char a[k+1];
    a[k--]='\0', a[0]=xx;
    while(x > 0 || k==nn-1) a[k--]='0'+x%10, x/=10;
    while(k>0)a[k--]=' ';
    printf("     %s\n", a);
}
int cc(){
    switch(c){
        case '\\':{ c='/'; return 1; }
        case 'x' :{ c='*'; return 1; }
        case 'X' :{ c='*'; return 1; }
        case '_' :{ c='-'; return 1; }
        default : return (c=='*' || c=='-' || c=='+' || c=='/' );
    }
}
void gEtOpErAtOr(){
    while(1){
        printf("Enter operator: ");
        c=getche();
        if(cc()) break;
        printerr(), Sleep(500), system("cls");
    }
}
void gEtvAlUEs(){
    n=2;
    while(c!='/'){
        ++err;
        if(err>10) exit(-1);
        system("cls");
        printf("In each problems:\n\nNumber of values: ");
        scanf("%d", &n);
        if(n>1) break;
        printerr(), Sleep(100);
    }
    while(1){
        ++err;
        if(err >10) exit(-2);
        system("cls");
        printf("\nLimit of values: ");
        scanf("%d", &m);
        if(m>10) break;
        printerr(), Sleep(100);
    }
}
int calculacione(int t, int x){
    switch(c){
        case '*' : return t*x;
        case '+' : return t+x;
        case '/' : { modt=t%x;  return t/x; }
        default : return t-x;
    }
}
void nusrat_pseudo_main(){
    system("cls");
    int x, ans;
    printf("Problem: (enter for answers)\n\n");
    for(int i=0; i<n; ++i){
        x=7+rand()%m;
        if(i)ans=calculacione(ans, x), outi(x, c);
        else ans=x, outi(x, ' ');
    }
    printf("     ");
    for(int i=0; i<nn; ++i)putchar('-');
    putchar('\n'), getch();
    outi(ans, '=');
    if(modt>0) printf("(mod = %d)", modt);
}
int logT(int m){
    int lans=0;
    while(m>0)++lans, m/=10;
    return lans;
}
int main(){
    gEtOpErAtOr(), gEtvAlUEs();
    nn=3+logT(m);
    do{
        nusrat_pseudo_main(n, m);
        Sleep(500), printf("\n\nContinue?\n");
    } while( !isalnum(getch()));
    return 0;
}

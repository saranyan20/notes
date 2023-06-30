#include <iostream>

using namespace std;

struct Stack {
    int top;
    int len;
    int *arr;
};

int push(struct Stack *s, int x){
    if(s->top == s->len-1)
        return 0;
    else {
        s->arr[++s->top] = x;
    }
}

int pop(struct Stack *s){
    int x = -1;
    if(s->top == -1)
        return 0;
    else {
        x = s->arr[s->top];
        s->top--;
    }
    return x;
}

void display(struct Stack s){
    for(int i=s.top ; i>=0 ; i--){
        cout << s.arr[i] << endl;
    }
}

int main()
{
    struct Stack s;
    cout << "Enter the length of the stack:";
    cin >> s.len;
    s.arr = new int[s.len];
    s.top = -1;

    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);

    pop(&s);

    display(s);


    return 0;
}

// Cài đặt tiếp cấu trúc SET, gồm max là số phần tử tối đa,
// n là số phần tử thực có của tập hợp, mảng động chứa các
// phần tử của tập hợp, hàm dựng (constructor), hàm hủy (destructor),
// các phép toán +, -, * để tìm hợp, hiệu, giao của 2 tập hợp.
// Lưu ý:
// - các phần tử của tập hợp lưu trữ theo thứ tự tăng dần,
// các phần tử của tập hợp không trùng nhau.
// - các hàm toán tử này không thay đổi trên toán hạng mà
// trả về kết quả cho hàm toán tử.
#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *LinkedList;

struct SET
{
    int *data;
    int n, max;
    SET(int sz = 10);
    SET(const SET &s);
    ~SET();
};

SET::SET(int sz)
{
    data = new int[sz];
    max = sz;
    n = 0;
}
SET::SET(const SET &s)
{
    n = s.n;
    max = s.max;
    data = new int[max];
    for (int i = 0; i < s.n; i++)
        data[i] = s.data[i];
}
SET::~SET()
{
    delete[] data;
    data = NULL;
}

Node *CreateNode(int value)
{
    Node *temp;
    temp = new Node;
    temp->next = NULL;
    temp->data = value;
    return temp;
}

LinkedList InitHead()
{
    LinkedList head;
    head = NULL;
    return head;
}

LinkedList AddTail(LinkedList head, int value)
{
    Node *temp, *p; // khai bao 2 node tam temp va p

    temp = CreateNode(value);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

LinkedList Input()
{
    LinkedList head = InitHead();
    int n, value;
    do
    {
        cout << "\nNhap so luong phan tu n: ";
        cin >> n;
    } while (n <= 0);

    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap gia tri can them: ";
        cin >> value;
        head = AddTail(head, value);
    }
    return head;
}

SET operator+(const SET &s, int x)
{
    int i, j;
    for (i = 0; i < s.n; i++)
    {
        if (s.data[i] == x)
            return s;
        if (s.data[i] > x)
            break;
    }

    SET s1 = s; // s1(s))
    for (int j = s.n; j > i; j--)
        s1.data[j] = s1.data[j - 1];
    s1.data[i] = x;
    s1.n++;
    return s1;
}

istream &operator>>(istream &in, LinkedList head)
{
    Input();
    return in;
};

ostream &operator<<(ostream &out, const SET &s)
{
    for (int i = 0; i < s.n; i++)
        cout << s.data[i] << " ";
    return out;
}

int main()
{
    SET s;
    cout << "Tao danh sach lien ket: ";
    cin >> s;
    cout << s + 3 + 5 + 7 << endl;
    cout << s + 4 << endl;
    return 0;
}

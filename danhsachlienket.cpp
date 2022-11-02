#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node *LinkedList;

Node *CreateNode(int value)
{
  Node *temp;
  temp = new Node;
  temp->next = NULL;
  temp->data = value;
  return temp;
}

// them vao dau danh sach
LinkedList AddHead(LinkedList head, int value)
{
  Node *temp = CreateNode(value);
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
  return head;
}

// them vao cuoi danh sach
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

// them vao vi tri bat ki
LinkedList AddAt(LinkedList head, int value, int position)
{
  if (position == 0 || head == NULL)
  {
    head = AddHead(head, value);
  }
  else
  {
    int k = 1;
    Node *p = head;
    while (p != NULL && k != position)
    {
      p = p->next;
      ++k;
    }
    if (k != position)
    {
      head = AddTail(head, value);
    }
    else
    {
      Node *temp = CreateNode(value);
      temp->next = p->next;
      p->next = temp;
    }
  }
  return head;
}

// xoa dau
LinkedList DelHead(LinkedList head)
{
  if (head == NULL)
  {
    cout << "khong co gi de xoa";
  }
  else
  {
    Node *p = head;
    head = head->next;
    delete p;
  }
  return head;
}

// xoa cuoi
LinkedList DelTail(LinkedList head)
{
  if (head == NULL || head->next == NULL)
  {
    return DelHead(head);
  }
  Node *p = head;
  while (p->next->next != NULL)
  {
    p = p->next;
  }
  Node *q = p->next;
  p->next = NULL;
  delete q;
  return head;
}

// xoa 1 vi tri bat ki
LinkedList DelAt(LinkedList head, int position)
{
  if (position == 0 || head == NULL || head->next == NULL)
  {
    head = DelHead(head);
  }
  else
  {
    int k = 1;
    Node *p = head;
    while (p->next->next != NULL && k != position)
    {
      p = p->next;
      ++k;
    }
    if (k != position)
    {
      head = DelTail(head);
    }
    else
    {
      Node *q = p->next;
      p->next = p->next->next;
      delete q;
    }
  }
  return head;
}

// lay gia tri o vi tri bat ki
int Get(LinkedList head, int index)
{
  int k = 0;
  Node *p = head;
  while (p->next != NULL && k != index)
  {
    ++k;
    p = p->next;
  }
  return p->data;
}

// tim kiem tra ve chi so Node dau tien co gia tri bang voi gia tri can tim
int Search(LinkedList head, int value)
{
  int position = 0;
  for (Node *p = head; p != NULL; p = p->next)
  {
    if (p->data == value)
    {
      return position;
    }
  }
  return -1;
}

LinkedList DelByVal(LinkedList head, int value)
{
  int position = Search(head, value);
  while (position != -1)
  {
    DelAt(head, position);
    position = Search(head, value);
  }
  return head;
}

void Traverser(LinkedList head)
{
  cout << endl;
  for (LinkedList p = head; p != NULL; p = p->next)
  {
    cout << p->data << "  ";
  }
}

LinkedList InitHead()
{
  LinkedList head;
  head = NULL;
  return head;
}

int Length(LinkedList head)
{
  int length = 0;
  for (LinkedList p = head; p != NULL; p = p->next)
  {
    ++length;
  }
  return length;
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

int main()
{
  int viTriThem, viTriXoa, soThem, soTim;

  cout << "\nTao 1 danh sach lien ket: ";
  LinkedList head = Input();
  Traverser(head);

  cout << "\nThu them 1 phan tu vao danh sach: ";
  cout << "\nNhap vi tri can them: ";
  cin >> viTriThem;
  cout << "Nhap so can them: ";
  cin >> soThem;
  head = AddAt(head, soThem, viTriThem);
  Traverser(head);

  cout << "\nThu xoa 1 phan tu khoi danh sach:";
  cout << "\nNhap vi tri can xoa: ";
  cin >> viTriXoa;
  head = DelAt(head, viTriXoa);
  Traverser(head);

  cout << "\nThu tim kiem 1 phan tu trong danh sach:";
  cout << "\nNhap so can tim: ";
  cin >> soTim;
  if (Search(head, soTim) == -1)
  {
    cout << "Khong tim thay so " << soTim;
  }
  else
  {
    cout << "Co so " << soTim << " trong danh sach";
  }

  return 0;
}
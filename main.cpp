#include <iostream>
#include <fstream>
#include <cstring>
#include "test/projecteuler/ans1.cpp"
#include "test/distances/EditDistance.cpp"

using namespace std;

int* stringLength(string* s);
int editDistance(int* s1, int* s2);
void show(int i);

typedef struct node {
    int* mod;
    struct node *next;
}NODE;

class LinkList {
private:
    NODE *head;
public:
    LinkList() { head = NULL; }
    ~LinkList() {
        NODE *p = head;
        while (head) {
            p = head;
            head = head->next;
            delete(p);
        }
    }
    bool Insert(int* e) {
        NODE* n = new NODE();
        n->mod = e;
        n->next = this->head;
        this->head = n;

    }

    void lookup() {
        NODE *p = head;
        while (p) {
            int *seq = p->mod;
            int count = 0;
            while (seq[count++]!=(int)'\n');

            int ind = 0;
            while (ind < count) {
                show(seq[ind]);
//                if (seq[ind] <= (1<<7) and seq[ind] > 0) {
//                    cout<<(char)seq[ind];
//                } else {
//                    string s="中";
//                    s[0]=(char)((seq[ind]>>16)-128);
//                    s[1]=(char)(((seq[ind]>>8)&255)-128);
//                    s[2]=(char)((seq[ind]&255)-128);
//                    cout<<s;
//                }
                ind++;
            }
            p = p->next;
        }
    }

    double similarity(int* lineStr) {
        int distance = 0, mindistance = 100000;
        double sim = 1.0d;
        double min = 1.0d;
        NODE *p = head;
        int l1=0;
        while (lineStr[l1++] != (int)'\n');
//        while (lineStr[l2++] != (int)'\n');
        int *watch = NULL;
        while (p) {
            int l2 = 0;
            while ((p->mod)[l2++] !=(int)'\n');
            distance = editDistance(lineStr, (p->mod));
            sim = (distance/(-distance + l1 + l2 + 0.0d));

            if (sim<min) {
                min = sim;
                watch = p->mod;
            }
            if (mindistance>distance) mindistance = distance;
            p = p->next;
        }
//        if (min>0.1) {
//            cout << "the diff: " << mindistance << ", sim: " << min << endl;
//            int i = 0;
//            if (watch)
//                while (*watch != (int) '\n') show(*watch++);
//            cout << endl;
//            while (lineStr[i] != 10) show(lineStr[i++]);
//            cout << endl;
//        }

        return min;
    }
};

int matrix[1000][1000];

void show(int i) {
    if (i <= (1<<7)-1 and i > 0) {
        cout<<(char)i;
    } else {
        string s="中";
        s[0]=(char)((i>>16)-128);
        s[1]=(char)(((i>>8)&255)-128);
        s[2]=(char)((i&255)-128);
        cout<<s;
    }
}

int editDistance(int* s1, int* s2) {
    int l1=0, l2=0;
    while (s1[l1++]!=(int)'\n');
    while (s2[l2++]!=(int)'\n');
//    vector< vector<int> > matrix (l1+1, vector<int> (l2+1, 0));

    // input2 are columns of the matrix, initialize the first row from 0 to size of input2
    for (unsigned int i = 0; i < l2+1; i++)
    {
        matrix[0][i] = i;
    }

    // input1 are rows of the matrix, initialize the first column from 0 to size of input1
    for (unsigned int i = 0; i < l1+1; i++)
    {
        matrix[i][0] = i;
    }

    //Edit Distance algorithm
    for (unsigned int i = 1; i < l1+1; i++)
    {
        for (unsigned int j = 1; j < l2+1; j++)
        {
            // Check if its a match
            if (s1[i-1]==s2[j-1])
            {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else
            {
                // Check if left element is lowest
                if (matrix[i][j-1] <= matrix[i-1][j] && matrix[i][j-1] <= matrix[i-1][j-1])
                {
                    matrix[i][j] = matrix[i][j-1] + 1;
                }
                    // Check if top element lowest
                else if (matrix[i-1][j] <= matrix[i][j-1] && matrix[i-1][j] <= matrix[i-1][j-1])
                {
                    matrix[i][j] = matrix[i-1][j] + 1;
                }
                    // Else its a diagonal
                else
                {
                    matrix[i][j] = matrix[i-1][j-1] + 1;
                }
            }
        }
    }

    //store the distance which is at the bottom right corner of the matrix
    int distance = matrix[l1][l2];
    return distance;

}

int* stringLength(string* s) {
    int count = 0;
    int pos = 0;
    while ((*s)[pos] != '\r' and (*s)[pos] != '\0') {
        count++;
        pos++;
        if (!((*s)[pos] >= 0 && (*s)[pos] <= 127))
            pos += 2;
    }

    pos = 0;
    int ind = 0;
    int* seq = (int*)malloc(sizeof(int) * (count+1));
    string special = "·";
    while (ind < count) {
        if ((*s)[pos]==special[0] && (*s)[pos+1]==special[1]) {
//            seq[ind] = '*';
            pos += 2;
            continue;
        } else if ((*s)[pos] >= 0 && (*s)[pos] <= 127 ) {
//            seq[ind] = (*s)[pos]+0;
            seq[ind] = '_';
            pos++;
        } else {
            seq[ind] = 0;
            seq[ind] |= (char)(*s)[pos++]+128;
            seq[ind] <<= 8;
            seq[ind] |= (char)(*s)[pos++]+128;
            seq[ind] <<=8;
            seq[ind] |= (char)(*s)[pos++]+128;
        }
        ind++;
    }
    seq[ind] = '\n';
    return seq;
}

int main() {
    ans10();
//    LinkList *ll = new LinkList();
//    ifstream inFile("/home/math/temp/untitled/data/newdata.csv", ios::in);
//    string lineStr;
//    int sup = 100000;
//    while (getline(inFile, lineStr) && sup--) {
//        // 打印整行字符串
//        int* seq = stringLength(&lineStr);
//        if (ll->similarity(seq) > 0.1) {
//            ll->Insert(seq);
//        }
//    }
//    sup = 100;
//    while (sup--)
//        cout<<'-';
//    cout<<endl;
//
//    ll->lookup();

    return 0;
}
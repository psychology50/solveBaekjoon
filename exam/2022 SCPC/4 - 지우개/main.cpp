#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

#define MAX 1000005

using namespace std;

string Answer;

vector<int> bad_char_type(string pattern, int size) {
    vector<int> bad_list(MAX, size);

    for (int i=0; i<size; i++) {
        bad_list[(int)pattern[i]] = i;
    }
    return bad_list;
}

vector<int> good_suffix_type(string pattern, int size) {
    int ptr = size;
    int sfx = ptr + 1;
    vector<int> bpos(size+1, 0);
    vector<int> shift(size+1, 0);

    while (ptr > 0) {
            cout << 2 << endl;
        while ((sfx <= size) && (pattern[ptr-1] != pattern[sfx-1])) {
            if (shift[sfx] == 0) {
                shift[sfx] == sfx - ptr;
            }
            sfx = bpos[sfx];
        }
        shift[--ptr] = --sfx;
    }

    sfx = bpos[0];
    while (ptr < size) {
        cout << 3 << endl;
        if (shift[ptr] == 0) shift[ptr] = sfx;
        if (ptr++ == sfx) sfx = bpos[sfx];
    }
    return shift;
}

int search(string str, string ptr, int str_sz, int ptr_sz) {
    if (str_sz < ptr_sz) return -1;
    vector<int> bc_list = bad_char_type(ptr, ptr_sz);
    vector<int> gs_list = good_suffix_type(ptr, ptr_sz);
    
    int start = 0;

    while (start <= str_sz - ptr_sz) {
        cout << 4 << endl;
        int is_valid = ptr_sz;
        while (is_valid > 0 && ptr[is_valid-1] == str[start + (is_valid - 1)])
        {
            --is_valid;
        }
        if (is_valid == 0) return start;
        if (bc_list[str[start + is_valid]] != ptr_sz)
        {
            start += max(is_valid - bc_list[str[start + is_valid]], gs_list[is_valid]);
        } else {
            start += max(gs_list[is_valid], is_valid);
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer = "";
        int n, m; cin >> n >> m;
        string str, pattern; cin >> str >> pattern;

        if (search(str, pattern, n, m) == -1) {
            Answer = "YES";
        } else {
            Answer = "NO";
        }
        
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}


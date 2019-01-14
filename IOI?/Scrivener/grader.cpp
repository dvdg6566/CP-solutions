#include<bits/stdc++.h>
using namespace std;

void Init();
void TypeLetter(char L);
void UndoCommands(int U);
char GetLetter(int P);

int main() {
  freopen("input.txt","r",stdin);
  Init();

  int cmd_num;
  scanf("%d", &cmd_num);

  int i;
  for (i = 0; i < cmd_num; i++) {
    char cmd;
    scanf(" %c", &cmd);
    if (cmd == 'T') {
      char letter;
      scanf(" %c", &letter);
      TypeLetter(letter);
    }
    else if (cmd == 'U') {
      int number;
      scanf("%d", &number);
      UndoCommands(number);
    }
    else if (cmd == 'P') {
      int index;
      char letter;
      scanf("%d", &index);
      letter = GetLetter(index);
      printf("%c\n", letter);
    }
  }

  return 0;

}

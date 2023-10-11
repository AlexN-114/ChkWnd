#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

HWND selbst;
char titel[300];

int FindWindowText(char *txt)
{
    HWND hwnd;
    int treffer = 0;
    static char hStr[300];
    
    printf("Suche: %s\n",txt);
    
    hwnd = FindWindow(NULL, NULL);

    while(hwnd != NULL)
    {
        if (hwnd != selbst)
        {
            GetWindowText(hwnd, hStr, 300);
             if (strstr(hStr,txt) != NULL)
            {
                printf("gefunden: %s\n", hStr);
                treffer++;
            }
        }
        hwnd = GetWindow(hwnd,GW_HWNDNEXT);            
    }
    SetConsoleTitle(titel);
    
    return treffer;
}

int main(int argc, char *argv[]) 
{
    selbst = GetConsoleWindow();
    
    GetConsoleTitle(titel, 300);
    // printf("titel: %s\n",titel);
    
    if (argc == 2)
    {
        SetConsoleTitle("?");
        Sleep(100);

        
        return FindWindowText(argv[1]);
    }
    printf("Verwendung: ChkWnd <Fenstertitel>\n%%ERRORLEVEL%% ist Anzahl Treffer\n");
	return 0;
}

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int FindWindowText(char *txt)
{
    HWND hwnd;
    int treffer = 0;
    static hStr[300];
    
    printf("Suche: %s\n",txt);
    
    hwnd = FindWindow(NULL, NULL);
    
    while(hwnd != NULL)
    {
        //TODO - Fenster suchen
        GetWindowText(hwnd, hStr, 300);
        if (strstr(hStr,txt) != NULL)
        {
            printf("gefunden: %s\n", hStr);
            treffer++;
        }
        hwnd = GetWindow(hwnd,GW_HWNDNEXT);
    }
    return treffer;
}

int main(int argc, char *argv[]) 
{
    if (argc == 2)
    {
        return FindWindowText(argv[1]);
    }
    printf("Verwendung: ChkWnd <Fenstertitel>\n%ERRORLEVEL% ist Anzahl Treffer\n");
	return 0;
}

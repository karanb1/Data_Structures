#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int x_max, x_min, y_max, y_min;

int compute_code(int x, int y)
{
    int code = INSIDE;
    if(x < x_min) code = LEFT;
    else if(x > m_max) code = RIGHT;
    if(y > y_max) code = TOP;
    else if(y < y_min) code = BOTTOM;
    return code;
}

void clip(int x1, int y1, int x2, int y2)
{
    int code1 = compute_code(x1, y1);
    int code2 = compute_code(x2, y2);
    while(true)
    {
        if((code1 == 0) && (code2 == 0))
        {
            rectangle(x_min, y_min, x_max, y_max);
            line(x1, y1, x2, y2);
            break;
        }
        else if(code1 == code2)
        {
            printf("Line reflected\n");
            break;
        }
        else
        {
            int code_out, x, y;
            if(code1 != 0) code_out = code1;
            else code_out = code2;
            if(code_out == TOP)
            {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
                line(x1, y1, x, y);
            }
            else if(code_out == BOTTOM)
            {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
                line(x, y, x2, y2);
            }
            else if(code_out == RIGHT)
            {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_min;
                line(x, y, x2, y2);
            }
            if(code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = compute_code(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = compute_code(x2, y2);
            }
        }
    }
}
void main()
{
    int gd = DETECT, gm, x1, x2, y1, y2;
    initgraph(&gd, &gm, "C://TC//BGI");
    printf("Enter Coordinates of bottom left vertex: ");
    scanf("%d %d", &x_min, &y_min);
    printf("Enter Coordinates of top right vertex: ");
    scanf("%d %d", &x_max, &y_max);
    printf("Enter Coordinates of starting point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter Coordinates of ending point: ");
    scanf("%d %d", &x2, &y2);
    clip(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;    
}
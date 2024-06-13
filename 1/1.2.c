#include<stdio.h>

main(){
    printf("Hello, World!\a"); // Audible bell or alert
    printf("\t<- \\a = Audible bell or alert\n");
    
    printf("Hello, World!\b"); // Backspace
    printf("\t<- \\b = Backspace\n");
    
    printf("Hello, World!\c"); // undefined
    printf("\t<- \\c = undefined\n");
    
    printf("Hello, World!\d"); // undefined
    printf("\t<- \\d = undefined\n");
    
    printf("\e[31mHello, world!\e[0m"); // ANSI escape
    printf("\t<- \\e = ANSI escape\n");
    
    printf("Hello, World!\f"); // Form feed
    printf("\t <- \\f = Form Feed (Move one line down)\n");
    
    printf("Hello, World!\g"); // undefined
    printf("\t<- \\g = undefined\n");

    printf("Hello, World!\h"); // undefined
    printf("\t<- \\h = undefined\n");
    
    printf("Hello, World!\i"); // undefined
    printf("\t<- \\i = undefined\n");
    
    printf("Hello, World!\j"); // undefined
    printf("\t<- \\j = undefined\n");
    
    printf("Hello, World!\k"); // undefined
    printf("\t<- \\k = undefined\n");

    printf("Hello, World!\l"); // undefined
    printf("\t<- \\l = undefined\n");

    printf("Hello, World!\m"); // undefined
    printf("\t<- \\m = undefined\n");

    printf("Hello, World!\n"); // New line
    printf("\t\t<- \\n = New Line\n");
    
        printf("Hello, World!\o{157}"); // Octal character
    printf("\t<- \\o{nnn} = Octal character (o being 157)\n");

    printf("Hello, World!\p"); // undefined
    printf("\t<- \\p = undefined\n");

    printf("Hello, World!\q"); // undefined
    printf("\t<- \\q = undefined\n");

    printf("Hello, World!\r"); // Return feed
    printf("\t\t<- \\r = Return feed (Set cursor to line start)\n");

    printf("Hello, World!\s"); // undefined
    printf("\t<- \\s = undefined\n");

    printf("Hello, World!\t"); // Horizontal Tab character
    printf("<- \\t = Horizontal Tab character\n");

    printf("Hello, World!\u{1F43C}"); // Unicode character
    printf("\t<- \\u = Unicode (C99+)\n");

    printf("Hello, World!\v"); // Vertical Tab Character
    printf("\t <- \\v = Vertical Tab Character\n");

    printf("Hello, World!\w"); // undefined
    printf("\t<- \\w = undefined\n");

    printf("Hello, World!\x78"); // Hexadecimal character
    printf("\t<- \\x = Hexadecimal character\n");

    printf("Hello, World!\y"); // undefined
    printf("\t<- \\y = undefined\n");

    printf("Hello, World!\z"); // undefined
    printf("\t<- \\z = undefined\n");
}
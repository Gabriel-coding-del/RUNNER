#include <ncurses.h>

char standing[][24] = {
    "    ooo             ",
    "  o#####o           ",
    " o#--#--#o          ",
    " o###/\\###o        ",
    "  o##--#o           ",
    "    o#o             ",
    "  /######\\          ",
    " /|runner|\\         ",
    "|#|##boy#|#|         ",
    "()|######|()         ",
    "  |##||##|           ",
    "  |##||##|           ",
    " <=()||()=>          "
};

char obstacle[][24] = {
    "/####\\",
    "|####|",
    "\\####/"
};

int main() {
    // Initialize ncurses
    initscr();
    keypad(stdscr, TRUE);   // Enable arrow key decoding
    noecho();               // Suppress key echoing
    curs_set(FALSE);        // Hide the cursor

    int num_lines = sizeof(standing) / sizeof(standing[0]);
    int pos_y = 5;          // Vertical position of the character
    int pos_x = 10;         // Horizontal position of the character

    // Draw the initial character
    for (int i = 0; i < num_lines; i++) {
        mvprintw(pos_y + i, pos_x, "%s", standing[i]);
    }
    refresh();

    int key;
    while ((key = getch()) != 'q') {
        // Erase previous character display
        for (int i = 0; i < num_lines; i++) {
            move(pos_y + i, pos_x);
            clrtoeol();
        }

        // Handle arrow key movement
        switch (key) {
            case KEY_UP:
                if (pos_y > 0) pos_y--;
                break;
            case KEY_DOWN:
                pos_y++;
                break;
            case KEY_LEFT:
                if (pos_x > 0) pos_x--;
                break;
            case KEY_RIGHT:
                pos_x++;
                break;
            default:
                break;
        }

        // Draw the character at the new position
        for (int i = 0; i < num_lines; i++) {
            mvprintw(pos_y + i, pos_x, "%s", standing[i]);
        }
        refresh();
    }

    endwin(); // Close ncurses window
    return 0;
}

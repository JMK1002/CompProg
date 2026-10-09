using namespace std;

int main() {
    while (true) {
        Sleep(50);
        if ((GetKeyState(VK_LBUTTON) & 0x80) != 0) {
            if (GetCursorPos(&p)) {
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            }
        }
        if ((GetKeyState(VK_RBUTTON) & 0x80) != 0) {
            break;
        }
    }
}
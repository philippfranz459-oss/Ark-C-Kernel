#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char id[20];
    char name[50];
    double balance;
    int is_active;
} Account;

typedef struct {
    char timestamp[30];
    char type[20]; // Deposit, Withdraw, Transfer
    double amount;
    double remaining;
} Transaction;

#define MAX_ACCOUNTS 1000
Account bank_system[MAX_ACCOUNTS];
int total_accounts = 0;

void get_time(char *buffer) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", timeinfo);
}
void create_account(char *name, double initial_deposit) {
    if (total_accounts >= MAX_ACCOUNTS) {
        printf("[ERROR] 系统内存已满，无法接收更多资产。\n");
        return;
    }

    Account new_acc;
    sprintf(new_acc.id, "ARK-%04d", total_accounts + 1001);
    strcpy(new_acc.name, name);
    new_acc.balance = initial_deposit;
    new_acc.is_active = 1;

    bank_system[total_accounts] = new_acc;
    total_accounts++;

    printf("[SUCCESS] 账户已建立 ID: %s, 所有人: %s\n", new_acc.id, new_acc.name);
}

void perform_transaction(char *acc_id, double amount, char *type) {
    for (int i = 0; i < total_accounts; i++) {
        if (strcmp(bank_system[i].id, acc_id) == 0) {
            if (strcmp(type, "WITHDRAW") == 0 && bank_system[i].balance < amount) {
                printf("[ALERT] 余额不足！当前资产: %.2f, 请求取款: %.2f\n", bank_system[i].balance, amount);
                return;
            }

            if (strcmp(type, "DEPOSIT") == 0) bank_system[i].balance += amount;
            if (strcmp(type, "WITHDRAW") == 0) bank_system[i].balance -= amount;

            char now[30];
            get_time(now);
            printf("[%s] 交易成功 | 类型: %s | 金额: %.2f | 剩余: %.2f\n", 
                    now, type, amount, bank_system[i].balance);
            return;
        }
    }
    printf("[ERROR] 未找到 ID 为 %s 的资产节点。\n", acc_id);
}

void save_data() {
    FILE *fp = fopen("ark_data.bin", "wb");
    if (fp == NULL) return;
    fwrite(&total_accounts, sizeof(int), 1, fp);
    fwrite(bank_system, sizeof(Account), total_accounts, fp);
    fclose(fp);
    printf("[SYSTEM] 所有加密资产已同步至本地存储。\n");
}

int main(void) {
    printf("==========================================\n");
    printf("   ARK WEALTH MANAGEMENT CORE v1.0        \n");
    printf("   xqh专属 2026 致富算法终端           \n");
    printf("==========================================\n");

    create_account("xqh", 10000.0); 
    
    int choice;
    double val;
    
    while(1) {
        printf("\n1.存款 | 2.取款 | 3.查看余额 | 4.保存退出\n请输入指令: ");
        scanf("%d", &choice);
        
        if (choice == 4) {
            save_data();
            break;
        }

        switch(choice) {
            case 1:
                printf("金额: "); scanf("%lf", &val);
                perform_transaction("ARK-1001", val, "DEPOSIT");
                break;
            case 2:
                printf("金额: "); scanf("%lf", &val);
                perform_transaction("ARK-1001", val, "WITHDRAW");
                break;
            case 3:
                printf("ID 为 ARK-1001 的当前资产: %.2f RMB\n", bank_system[0].balance);
                break;
            default:
                printf("无效指令。\n");
        }
    }

    return 0;
}
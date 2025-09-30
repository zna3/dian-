#include<stdio.h>
#include<string.h>

int main(){
    char input[10];
    char user = ' ';  
    
    while(1){
        scanf("%s", input);
        
        if(strcmp(input, "Quit") == 0){
            break;
        }
        else if(strcmp(input, "Login") == 0){
            if(user != ' '){
                printf("已登录\n");
            } else {
                printf("输入用户名(A-Z): ");
                scanf(" %c", &user);  
                
                if(user >= 'A' && user <= 'Z'){
                    printf("登录成功\n");
                } else {
                    printf("用户名错误\n");
                    user = ' ';
                }
            }
        }
        else if(strcmp(input, "Exit") == 0){
            if(user != ' '){
                printf("退出登录\n");
                user = ' ';
            } else {
                printf("未登录\n");
            }
        }
        else{
            printf("错误指令\n");
        }
    }
    
    return 0;
}

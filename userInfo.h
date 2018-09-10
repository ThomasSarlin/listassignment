typedef struct user_info{
	unsigned int uid;
	char* uname;
}user_info;

user_info* userInfo_create(unsigned int, char*);
bool userInfo_compare(void* u1,void* u2);
void userInfo_swap(void* u1, void* u2);
unsigned int userInfo_getUid(user_info*);
char* userInfo_getUname(user_info*);

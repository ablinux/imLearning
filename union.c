#include <stdio.h>
#include <stdint.h>
/* test 1*/
union arm_reg
{
	int a;
	char b;
};

union ipv4
{
	struct ip
	{
		char a; // ip in human readable formate
		char b;
		char c;
		char d;
	} ip_t;
	uint32_t ipaddr_to_card; // the ip that we can assign to network card
};

int main()
{
	union arm_reg io;
	io.a = 0x12345678;
	printf("Basic test io.a = 10\nio.b = 11\nAnswer should be 11\n\nResult:\n");
	printf("io.a = %x\n", io.a);
	printf("io.b = %x\n", io.b);
	printf("Size of union arm_reg = %d bytes\n", sizeof(io));

	char *p = &io.b;
	printf("%x  %x  %x  %x\n", p[0], p[1], p[2], p[3]);

	printf("\n\n\nExample 2 HOW IP Address is stored using union\n");

	union ipv4 sourceIPaddr;
	sourceIPaddr.ip_t.a = 192;
	sourceIPaddr.ip_t.b = 168;
	sourceIPaddr.ip_t.c = 1;
	sourceIPaddr.ip_t.d = 121;

	printf("Size of union ipv4 = %d bytes\n", sizeof(sourceIPaddr));

	printf("IP add that will be assigned to card = %d\n", sourceIPaddr.ipaddr_to_card);

	printf("Now converting the network card IP addr to User reable ip addr\n");

	union ipv4 destip;
	destip.ipaddr_to_card = sourceIPaddr.ipaddr_to_card;

	printf("From card ip to readable IP: (%d,%d,%d,%d)\n", destip.ip_t.a, destip.ip_t.b, destip.ip_t.c, destip.ip_t.d);
}
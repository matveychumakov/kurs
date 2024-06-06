#include <UnitTest++/UnitTest++.h>
#include "Client.h"

using namespace std;

struct Cons_fix {
	Client * p;
	Cons_fix() {
		p = new Client();
	}
	~Cons_fix() {
		delete p;
	}
};

SUITE(interactWithServer) {

    TEST_FIXTURE(Cons_fix, IncorrectIPAddress){
		p->setServerAddress(123456);
        p->setServerPort(33333);
        p->setInputDataFile("/home/stud/123/vectors.bin");
        p->setOutputDataFile("/home/stud/123/res.bin");
        p->setClientCredentialsFile("/home/stud/123/config/vclient.conf");
        CHECK_THROW(p->interactWithServer(), ErrorManager);
	}

	TEST_FIXTURE(Cons_fix, IncorrectPortNumber){
		p->setServerAddress(2130706433);
        p->setServerPort(33335);
        p->setInputDataFile("/home/stud/123/vectors.bin");
        p->setOutputDataFile("/home/stud/123/res.bin");
        p->setClientCredentialsFile("/home/stud/123/config/vclient.conf");
        CHECK_THROW(p->interactWithServer(), ErrorManager);
	}

	TEST_FIXTURE(Cons_fix, ErrorOpeningLoginAndPasswordFile){
		p->setServerAddress(2130706433);
        p->setServerPort(33333);
        p->setInputDataFile("/home/stud/123/vectors.bin");
        p->setOutputDataFile("/home/stud/123/res.bin");
        p->setClientCredentialsFile("/home/stud/123/config/bvclient.conf");
        CHECK_THROW(p->interactWithServer(), ErrorManager);
	}

	TEST_FIXTURE(Cons_fix, IdentificationError){
		p->setServerAddress(2130706433);
        p->setServerPort(33333);
        p->setInputDataFile("/home/stud/123/vectors.bin");
        p->setOutputDataFile("/home/stud/123/res.bin");
        p->setClientCredentialsFile("/home/stud/123/config/ierror.conf");
        CHECK_THROW(p->interactWithServer(), ErrorManager);
	}

	TEST_FIXTURE(Cons_fix, AuthenticationError){
		p->setServerAddress(2130706433);
        p->setServerPort(33333);
        p->setInputDataFile("/home/stud/123/vectors.bin");
        p->setOutputDataFile("/home/stud/123/res.bin");
        p->setClientCredentialsFile("/home/stud/123/config/aerror.conf");
        CHECK_THROW(p->interactWithServer(), ErrorManager);
	}

	TEST_FIXTURE(Cons_fix, ErrorOpeningVectorsFile){
		p->setServerAddress(2130706433);
        p->setServerPort(33333);
        p->setInputDataFile("/home/stud/123/bvectors.bin");
        p->setOutputDataFile("/home/stud/123/res.bin");
        p->setClientCredentialsFile("/home/stud/123/config/vclient.conf");
        CHECK_THROW(p->interactWithServer(), ErrorManager);
	}


}

int main()
{
	return UnitTest::RunAllTests();
}

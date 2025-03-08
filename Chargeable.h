#ifndef CHARGEABLE_H
#define CHARGEABLE_H

using namespace std;

class Chargeable {

public:
	virtual void recharge(int amount) override;
};

#endif
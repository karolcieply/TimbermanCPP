#include "Classes.h"

void Timberman::ChangePosition(positionEnum temp) {
	playerPosition = temp;
}
Timberman::Timberman() {
	playerPosition = right;
}
Branch::Branch() {
	branchPosition = Timberman::positionEnum::left;
}

#include "Classes.h"
ResourcesManager resManager;
void ResourcesManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;

	if (tex.loadFromFile(fileName))
	{
		this->textures[name] = tex;
	}
}

sf::Texture& ResourcesManager::GetTexture(std::string name)
{
	return this->textures.at(name);
}

void ResourcesManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->fonts[name] = font;
	}
}

sf::Font& ResourcesManager::GetFont(std::string name)
{
	return this->fonts.at(name);
}

void ResourcesManager::SaveTopScores() {
	outputFile.open(HIGH_SCORES_FILE);
	for (int i = 0; i < 20; i+=2) {
		outputFile << topScores[i]<<" "<<topScores[i+1]<<"\n";
	}
	outputFile.close();
}

std::string ResourcesManager::GetTime()
{
	std::string date;
	GetSystemTime(&st);
	date += std::to_string(st.wDay);
	date += "-";
	date += std::to_string(st.wMonth);
	date += "-";
	date += std::to_string(st.wYear);
	date += ":";
	date += std::to_string(st.wHour+2);
	date += ".";
	date += std::to_string(st.wMinute);
	return date;
}

void ResourcesManager::LoadTopScores()
{
	inputFile.open(HIGH_SCORES_FILE);
	for (int i = 0; i < 20; i++) {
		inputFile >> topScores[i];
	}
	inputFile.close();
	return;
}

void ResourcesManager::UpdateArray(unsigned int score){
	if (stoi(this->topScores[18]) < score) {
		topScores[18] = std::to_string(score);
		topScores[19] = GetTime();
		for (int i = 8; i >= 0; i--) {
			if (stoi(this->topScores[i * 2]) < score) {
				std::swap(topScores[i * 2], topScores[(i + 1) * 2]);
				std::swap(topScores[(i * 2) + 1], topScores[((i + 1) * 2) + 1]);
			}
			else return;
		}
	}
	return;
}
unsigned int ResourcesManager::GetTopScore() {
	return stoi(topScores[0]);
}
std::string ResourcesManager::GetWholeScore(int which) {
	return topScores[2 * which] +" "+ topScores[2 * which + 1];
}
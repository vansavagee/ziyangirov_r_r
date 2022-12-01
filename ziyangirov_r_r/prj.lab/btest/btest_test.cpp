#include<vector>
#include <algorithm>
#include <iterator>
#include<set>
#include<matplot/matplot.h>
#include <unordered_set>
#include <chrono>
#include <string>
#include <fstream>
#include <iomanip>
#include<random>
#include <locale>
#include <codecvt>
const int MAXN = 200000;
typedef std::pair<std::vector<double>, std::vector<double>> coolpair;
double converted(std::vector<double> tmp) {
	double s = std::accumulate(tmp.begin(), tmp.end(), 0.0) / tmp.size();
	return s;
}
using namespace matplot;
int main() {
	std::ofstream fileinput;
	std::ifstream fileoutput;
	coolpair resinput;
	coolpair resalg;
	std::vector<int> ndata;

	int c = 1;
	for (int n = 10000; n <= MAXN; n += 10000) {
		ndata.push_back(n);
		coolpair tmpinp;
		coolpair tmpalg;
		const int k = n/100;
		// генерация вводимых данных 
		int j = 1;
		for (int m = k; m < n; m += k) {
			fileinput.open("C:\\gg\\test.txt");
			if (fileinput.is_open()) {
				   fileinput << n << std::endl;
			}
			for (int i = 0; i < n; i++) {
				if (j <= m) {
					if (fileinput.is_open()) {
						fileinput << j << std::endl;
					}
					j++;
				}
				else {
					j = 1;
				}
			}
		// подсчет времени для ввода для двух решений
			int n1 = 0;
			auto start_input_1 = std::chrono::high_resolution_clock::now();
			fileoutput.open("C:\\gg\\test.txt");
			std::vector<int> as(200001, -1);
			if (fileoutput.is_open())
			{
				fileoutput >> n1;

				for (int i = 0; i < n1; i += 1)
				{
					int idx = 0;
					fileoutput >> idx;
					as[idx] = n1 - i - 1;
				}
			}
			auto end_input_1 = std::chrono::high_resolution_clock::now();
			
			
			tmpinp.first.push_back((end_input_1 - start_input_1).count());
			
			
			fileoutput.seekg(0, std::ios_base::beg);
			fileoutput.close();
			
			
			int n2 = 0;			
			auto start_input_2 = std::chrono::high_resolution_clock::now();
			fileoutput.open("C:\\gg\\test.txt");
			if (fileoutput.is_open())
				fileoutput >> n2;
			std::vector<int> data(n2, 0);
			if (fileoutput.is_open())
			{
				for (int i = 0; i < n2; i += 1)
				{
					fileoutput >> data[i];
				}
			}
			auto end_input_2 = std::chrono::high_resolution_clock::now();
			fileoutput.close();
			fileoutput.open("C:\\gg\\test.txt", std::ofstream::out | std::ofstream::trunc);
			fileoutput.close();

			tmpinp.second.push_back((end_input_2 - start_input_2).count());
			
			// подсчет времени работы алгоритмов для двух решений 
			int k1 = 0;
			auto start_program_1 = std::chrono::high_resolution_clock::now();
			k1 = std::distance(as.begin(), std::max_element(as.begin(), as.end()));
			auto end_program_1 = std::chrono::high_resolution_clock::now();
			
			
			tmpalg.first.push_back((end_program_1 - start_program_1).count());
			
			
			auto start_program_2 = std::chrono::high_resolution_clock::now();
			std::unordered_set<int> unique;
			unique.reserve(200000);
			int idx_unique = n;
			for (int i = n2 - 1; 0 <= i; i -= 1)
			{
				if (!unique.contains(data[i])) {
					idx_unique = data[i];
					unique.insert(idx_unique);
				}
			}
			auto end_program_2 = std::chrono::high_resolution_clock::now();
			
			
			tmpalg.second.push_back((end_program_2 - start_program_2).count());

		}
		
		 resinput.first.push_back(converted(tmpinp.first)/n);
		 resinput.second.push_back(converted(tmpinp.second)/n);
		 resalg.first.push_back(converted(tmpalg.first)/n);
		 resalg.second.push_back(converted(tmpalg.second)/n);
}
 //построение графиков
tiledlayout(2, 1);
nexttile();
subplot(2, 1, 0);
title("Ввод данных в первом решении задачи");
plot(ndata, resinput.first, "-xr");
ylabel("t/n");
xlabel("n");
save("resinputfirst.png");


tiledlayout(2, 1);
nexttile();
subplot(2, 1, 0);
title("Ввод данных во втором решении задачи");
plot(ndata, resinput.second, "-xr");
ylabel("t/n");
xlabel("n");
save("resinputsecond.png");

tiledlayout(2, 1);
nexttile();
subplot(2, 1, 0);
title("Работа алгоритмической части в первом решении");
plot(ndata, resalg.first, "-xr");
ylabel("t/n");
xlabel("n");
save("resalgfirst.png");

tiledlayout(2, 1);
nexttile();
subplot(2, 1, 0);
title("Работа алгоритмической части во втором решении");
plot(ndata, resalg.second, "-xr");
ylabel("t/n");
xlabel("n");
save("resalgsecond.png");


std::wofstream finalreport;
// создание .tex документа 
finalreport.open("C:\\prgm\\proga\\ziyangirov_r_r\\prj.lab\\btest\\out\\build\\x64-Debug\\Ziyangirov_Ravil_21-3.tex");
if (finalreport.is_open())
{
	finalreport << "\\documentclass{article}\n";
	finalreport << "\\usepackage{cmap}\n";
	finalreport << "\\usepackage[T2A]{fontenc}\n";
	finalreport << "\\usepackage{indentfirst}\n";
	finalreport << "\\usepackage{graphicx}\n";
	finalreport << "\\usepackage[utf8]{inputenc}\n";
	finalreport << "\\usepackage[english,russian]{babel}\n";
	finalreport << "\\frenchspacing\n";
	finalreport << "\\title{Отчёт}\n";
	finalreport << "\\author{Зиянгиров Равиль БПМ-21-3}\n";
	finalreport << "\\date{01.12.2022}\n";
	finalreport << "\\begin{document}\n";
	finalreport << "\\maketitle\n";
	finalreport << "\\textbf{github:} \\href{https://github.com/vansavagee/ziyangirov\\_r\\_r/tree/main/ziyangirov\\_r\\_r/prj.lab/btest}\n";
	finalreport << "\\section{Описание работы}\n";
	finalreport << "Требовалось произвести необходимые замеры времени и изготовить отчёт. Мною были проведены 10 замеров времени каждого предложенного кода отдельно отдельно для ввода данных и алгоритмической части(всего 40 замеров), в зависимости от m - количества различных столовых и было найдено среднее время этих 10 замеров(каждый замер - новое количество различных столовых) для ввода данных и для алгоритмической части двух предложенных кодов.\n";
	finalreport << "Следующие 4 графика - это графики зависимостей t/n от n, где \\textbf{}t - это усредненное время 10 замеров с разным m работы того или иного участка кода, \\textbf{n} - это количество введенных данных.\n";
	finalreport << "\\textbf{n} меняется от 10000 до 200000 с шагом в 10000. \n";
	finalreport << "\\section{Графики зависимостей}\n";
	finalreport << "\\includegraphics[scale=0.6]{resinputfirst}    \n";
	finalreport << "\\includegraphics[scale=0.6]{resinputsecond}\n";
	finalreport << "\\includegraphics[scale=0.6]{resalgfirst}\n";
	finalreport << "\\includegraphics[scale=0.5]{resalgsecond}\n";
	finalreport << "\\section{Вывод по замерам}  \n";
	finalreport << "Первый код считывает данные дольше чем второй, однако алгоритмическая часть первого кода работает быстрее. \n";
	finalreport << "\\end{document}\n";
}
finalreport.close();
	return 0;
}
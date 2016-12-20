#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>
#include<boost/tokenizer.hpp>

using namespace boost::algorithm;
using namespace std;
using namespace boost;

int main()
{
	std::string s = "-- 123fooo--123--";
	trim_left_if(s, is_any_of("-")); //Удаляет во входной строке слева символы "-"
	cout << trim_copy_if(s, is_any_of("-")) << endl;//Возвращает строку с обрезанными слева и справа символами "-"
	trim_if(s, is_any_of("-"));//Обрезвает во входной строке слева и справа символы "-"
	cout << trim_right_copy_if(s, is_digit()) << endl; //Возвращает строку с удаленными справа цифрами
	trim_if(s, is_digit()); //Обрезвает во входной строке цифры
	trim(s); //Удаляет во входной строке пробелы.
	cout << s << endl;


	cout.setf(std::ios::boolalpha);
	cout << starts_with(s, "123") << endl; //Проверяет, начинается ли строка с данной подстроки
	cout << ends_with(s, "-") << endl; //Проверяет, заканчивается ли строка данной подстрокой
	cout << contains(s, "--123f") << endl; //Проверяет, содержит ли строка данную подстроку
	cout << lexicographical_compare(s, "0") << endl;//Проверяет меньше ли данная строка подстроки в лексикографическом смысле


	boost::iterator_range<std::string::iterator> r = find_first(s, "123"); //Ищет первое вхождение подстроки в строку
	cout << r << endl;
	r = find_last(s, "xyz");//Ищет последнее вхождение подстроки в строку
	cout << r << endl;

	cout << replace_first_copy(s, "-", "+") << endl;//Возваращает строку, в которой первое вхождение первой подстроки меняет на вторую

	tokenizer<boost::char_separator<char>> tok(s);
	for (tokenizer<boost::char_separator<char>>::iterator beg = tok.begin(); beg != tok.end(); ++beg){//Выводим выражения с разделителями
		cout << *beg << endl;
	}

	erase_first(s, "123"); //Удаляем первое вхождение "123" ->  fooo--
	erase_nth(s, "f", 0); //Удаляем первое вхождение "f" -> ooo--
	erase_last(s, "--"); //Удаляем последнее вхождение "--" -> ooo
	erase_all(s, "o"); //Удаляем все "ooo" ->

	cout << s;//Пусто
}
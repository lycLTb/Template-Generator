#include <bits/stdc++.h>
#include <io.h>
using namespace std;
vector<string> files, filenames;
namespace strs {
string start = "<!DOCTYPE html>\n<html>\n<head>\n<title>Templates</title>\n";
string start_to_body = "</head>\n<body>";
string end = "</body>\n</html>";
string pos = "code";
string code_start = "<pre><code class=\"language-c++\">";
string code_end = "</code></pre>";
}

vector<string> getFiles(string path)
{
	vector<string> files;
	long hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do {
			if (!(fileinfo.attrib & _A_SUBDIR))
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	return files;
}

void putfile(string cls, string ecls, string path, bool code)
{
	cout << cls;
	vector<char> v;
	if (FILE* fp = fopen(path.data(), "r")) {
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			v.insert(v.end(), buf, buf + len);
		fclose(fp);
	}
	for (int i=0;i<(int)v.size();i++) {
		if (v[i] == '<' && code)
			cout << "&lt";
		else if (v[i] == '>' && code)
			cout << "&gt";
		else
			cout << v[i];
	}
	cout << ecls << endl;
}

vector<string> getfilenames(vector<string> files)
{
	vector<string> ans;
	for (int i=0;i<(int)files.size();i++) {
		string s=files[i];
		string tmp = "";
		for (int i = strs::pos.size() + 1; s[i] != '.' && i <= (int)s.size(); i++)
			tmp += s[i];
		ans.push_back(tmp);
	}
	return ans;
}

void g_content(string s)
{
	cout << "<a class=\"content\" href=\"#" + s + "\"><center>" + s + "</center></a>";
	cout << "<br>\n";
}

void g_code(int Index)
{
	cout << "<h3 class=\"code\" id=\"" << filenames[Index] << "\">" << filenames[Index] << "</h2>" << endl;
	putfile(strs::code_start, strs::code_end, files[Index], true);
	cout << "<a class=\"top\" href=\"#content\">Top</a>" << endl;
}

int main()

{
	freopen("Templates.html", "w", stdout);
	files = getFiles(strs::pos);
	cout << strs::start << endl;
	putfile("<script>", "</script>", "source\\jquery.js", false);
	putfile("<script>", "</script>", "source\\prism.js", false);
	putfile("<style>", "</style>", "source\\Mycss.css", false);
	putfile("<style>", "</style>", "source\\prism.css", false);
	cout << strs::start_to_body << endl;
	putfile("<script>", "</script>", "source\\copy.js", false);
	filenames = getfilenames(files);

	cout << "<h2 id=\"content\">Content</h2>" << endl;
	for (int i = 0; i < (int)filenames.size(); i++)
		g_content(filenames[i]);
	cout << "<br>" << endl;

	for (int i = 0; i < (int)files.size(); i++)
		g_code(i);
	cout << strs::end << endl;
	return 0;
}
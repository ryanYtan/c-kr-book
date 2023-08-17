/**
 * Exercise 3-02
 *
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like "\n" and "\t" as it copies the string t to
 * s. Use a switch. Write a function for the other direction as well, converting
 * escape sequences into real characters
 */
#include <assert.h>
#include <string.h>
#include "../../utility.h"

void escape(char s[], char t[])
{
        int j = 0;
        for (int i = 0; t[i] != '\0';)
        {
                switch (t[i])
                {
                case '\b':
                        s[j++] = '\\';
                        s[j++] = 'b';
                        break;
                case '\n':
                        s[j++] = '\\';
                        s[j++] = 'n';
                        break;
                case '\r':
                        s[j++] = '\\';
                        s[j++] = 'r';
                        break;
                case '\t':
                        s[j++] = '\\';
                        s[j++] = 't';
                        break;
                default:
                        s[j++] = t[i];
                        break;
                }
                i++;
        }
        s[j] = '\0';
}

void unescape(char s[], char t[])
{
        int j = 0;
        for (int i = 0; t[i] != '\0';)
        {
                if (t[i] == '\\' && t[i + 1] != '\0')
                {
                        switch (t[i + 1])
                        {
                        case 'b':
                                s[j++] = '\b';
                                i += 2;
                                break;
                        case 'n':
                                s[j++] = '\n';
                                i += 2;
                                break;
                        case 'r':
                                s[j++] = '\r';
                                i += 2;
                                break;
                        case 't':
                                s[j++] = '\t';
                                i += 2;
                                break;
                        default:
                                s[j++] = t[i++];
                                break;
                        }
                }
                else
                {
                        s[j++] = t[i++];
                }
        }
        s[j] = '\0';
}

int main()
{
        //testing escape
        {
                char s[100] = { 0 };
                escape(s,"\b\n\t");
                assert(strcmp(s, "\\b\\n\\t") == 0);
        }
        {
                char *t = "\nthe first\\\bline/\b\nthe second line\n";
                char s[100] = { 0 };
                escape(s, t);
                assert(strcmp(s, "\\nthe first\\\\bline/\\b\\nthe second line\\n") == 0);
        }


        //testing unescape
        {
                char s[100] = { 0 };
                unescape(s,"\\b\\n\\t");
                assert(strcmp(s, "\b\n\t") == 0);
        }
        {
                char *t = "\\nthe first\\\\bline/\\b\\nthe second line\\n";
                char s[100] = { 0 };
                unescape(s, t);
                assert(strcmp(s, "\nthe first\\\bline/\b\nthe second line\n") == 0);
        }

        print_tc_success();
}

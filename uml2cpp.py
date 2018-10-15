#! /usr/bin/env python

from enum import Enum
from sys import stdin

class Acess(Enum):
    PUBLIC = "+"
    PROTECTED = "*"
    PRIVATE = "-"

class Modifier(Enum):
    EMPTY = ""
    METHOD = "method"
    ABSTRACT = "abstract"
    VIRTUAL = "virtual"
    OVERRIDE = "override"


class CppVar:
    acess = Acess.PUBLIC
    content = ""


class CppMethod:
    modifier = Modifier.METHOD
    acess = Acess.PUBLIC
    content = ""


class CppClass:
    class_name = ""
    cpp_pub_vars = []
    cpp_pub_methods = []
    cpp_pro_vars = []
    cpp_pro_methods = []
    cpp_prv_vars = []
    cpp_prv_methods = []
    mode = Modifier.EMPTY

    def get_acess(self, line):
        for s in list(Acess):
            index = line.find(s.value)
            if index != -1:
                return index, s
        return -1, Acess.PUBLIC


    def process_line(self, line):
        words = line.split()
        if "class" in words:
            self.class_name = words[words.index("class") + 1]
            return

        for word in list(Modifier):
            if word.value in words:
                self.mode = word
                return

        if self.mode != Modifier.EMPTY:
            index, acess = self.get_acess(line)
            if index == -1:
                return
            method = CppMethod()
            method.acess = acess
            method.content = line[index+1:]
            method.modifier = self.mode
            if method.acess == Acess.PUBLIC:
                self.cpp_pub_methods.append(method)
            elif method.acess == Acess.PROTECTED:
                self.cpp_pro_methods.append(method)
            else:
                self.cpp_prv_methods.append(method)

        else:
            var = CppVar()
            index, var.acess = self.get_acess(line)
            var.content = line[index+1:]
            if method.acess == Acess.PUBLIC:
                self.cpp_pub_vars.append(var)
            elif var.acess == Acess.PROTECTED:
                self.cpp_pro_vars.append(var)
            else:
                self.cpp_prv_vars.append(var)

    def add_methods_declaration(self, methods):
        cpp_header = ""
        for method in methods:
            if method.modifier == Modifier.ABSTRACT:
                cpp_header += ("virtual " + method.content + " = 0;\n")
            elif method.modifier == Modifier.VIRTUAL:
                cpp_header += ("virtual " + method.content + ";\n")
            elif method.modifier == Modifier.OVERRIDE:
                cpp_header += ("virtual " + method.content + " override;\n")
            else:
                cpp_header += (method.content + ";\n");
        return cpp_header

    def add_var_declaration(self, varss):
        cpp_header = ""
        for var in varss:
            cpp_header += var.content + "\n";
        return cpp_header


    def generate_cpp_header(self):
        cpp_header = "class " + self.class_name;
        cpp_header += " : public Object {\n"

        cpp_header += "public:\n"
        cpp_header += self.add_methods_declaration(self.cpp_pub_methods)
        print(len(self.cpp_pub_methods))
        cpp_header += self.add_var_declaration(self.cpp_pub_vars)

        cpp_header += "protected:\n"
        cpp_header += self.add_methods_declaration(self.cpp_pro_methods)
        cpp_header += self.add_var_declaration(self.cpp_pro_vars)

        cpp_header += "private:\n"
        cpp_header += self.add_methods_declaration(self.cpp_prv_methods)
        cpp_header += self.add_var_declaration(self.cpp_prv_vars)

        cpp_header += "};\n"

        return cpp_header


if __name__ == "__main__":
    cpp_class = CppClass();
    for line in stdin.read().split('\n'):
        cpp_class.process_line(line)
    print(cpp_class.generate_cpp_header())





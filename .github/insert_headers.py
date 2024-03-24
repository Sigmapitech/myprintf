from datetime import datetime

import pathlib
import os

PROJECT_NAME = "my_printf"

_HEADER_UNIT = (
    "/*\n"
    "** EPITECH PROJECT, {year}\n"
    "** {project_name}\n"
    "** File description:\n"
    "** {filename}\n"
    "*/\n"
)

_HEADER_MK = (
    "##\n"
    "## EPITECH PROJECT, {year}\n"
    "## {project_name}\n"
    "## File description:\n"
    "## {filename}\n"
    "##\n"
)

HEADER_TEMPLATE = {
    'h': _HEADER_UNIT,
    'c': _HEADER_UNIT,
    'e': _HEADER_MK,
    'k': _HEADER_MK
}


def insert_header_in_file(dirs: str, filename: str):
    filepath = os.path.join(dirs, filename)
    file_content = pathlib.Path(filepath).read_text()

    header = HEADER_TEMPLATE[filename[-1]].format(
        year=datetime.now().year,
        project_name=PROJECT_NAME,
        filename=filename
    )

    with open(filepath, "w+") as f:
        f.write(f"{header}\n{file_content}")



def main():
    for dirs, _, files in os.walk("."):
        for filename in files:
            if not any(
                filename.endswith(ext)
                for ext in { ".c", ".h", ".mk", "Makefile" }
            ):
                continue

            insert_header_in_file(dirs, filename)


if __name__ == "__main__":
    main()

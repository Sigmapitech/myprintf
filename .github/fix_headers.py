from __future__ import annotations

import os
from datetime import datetime
from enum import StrEnum
from pathlib import Path
from typing import List, Final, Dict

from file import File, FileType

PROJECT: Final[str] = "my_printf"
YEAR: Final[int] = datetime.now().year
SENTINEL: Final[int] = -1
MAKEFILE_COMMENT: Final[str] = "##"

HEADERS: Dict[FileType, str] = {
    FileType.SOURCE: Path(".github/templates/c.header").read_text(),
    FileType.MAKEFILE: Path(".github/templates/mk.header").read_text()
}


class CToken(StrEnum):
    BLOCK_COMMENT_START = "/*"
    BLOCK_COMMENT_END = "*/"


class HFile(File):

    def fix_header(self):
        header_template = HEADERS.get(self.type)

        if not header_template:
            return

        header = header_template.format(
            year=YEAR,
            filename=self.fullname,
            project=PROJECT
        )

        content = self.read()
        if content.startswith(header):
            return

        print("Formatting", self.path)
        lines = content.splitlines()
        lineno = get_first_code_line(self.type, lines)
        keep = '\n'.join(lines[lineno:])

        with open(self.path, 'w') as f:
            f.write(f"{header}{keep}\n")


def get_first_code_line(file_type: FileType, lines: List[str]) -> int:
    start = get_first_non_empty_line(lines)
    line_count = len(lines)

    if start > line_count:
        return SENTINEL

    if file_type == FileType.SOURCE:
        if CToken.BLOCK_COMMENT_START not in lines[start]:
            return start

        while (
            start < line_count
            and CToken.BLOCK_COMMENT_END not in lines[start]
        ):
            start += 1
    else:
        if MAKEFILE_COMMENT not in lines[start]:
            return start

        while start < line_count and MAKEFILE_COMMENT in lines[start]:
            start += 1
        start -= 1

    return get_first_non_empty_line(lines, start + 1)


def get_first_non_empty_line(lines: List[str], from_id: int = 0) -> int:
    line_count = len(lines)

    if from_id >= line_count:
        return SENTINEL

    while lines[from_id].isspace():
        from_id += 1

    return from_id


def main():
    for directory, _, files in os.walk('.'):
        for filename in files:
            filename, ext = os.path.splitext(filename)

            file = HFile(directory, filename, ext[1::])
            file.fix_header()


if __name__ == '__main__':
    main()

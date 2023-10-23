from __future__ import annotations
from enum import Enum, auto
from dataclasses import dataclass


class FileType(Enum):
    SOURCE = auto()
    MAKEFILE = auto()
    OTHER = auto()

    @classmethod
    def from_file(cls, file: File):
        if file.ext == 'c' or file.ext == 'h':
            return cls.SOURCE

        if file.ext == 'mk' or file.name == 'Makefile':
            return cls.MAKEFILE

        return cls.OTHER


@dataclass
class File:
    dir: str
    name: str
    ext: str

    def __post_init__(self):
        self.type: FileType = FileType.from_file(self)

    @property
    def fullname(self):
        if not self.ext:
            return self.name

        return f"{self.name}.{self.ext}"

    @property
    def path(self):
        if not self.dir or self.dir == '.':
            return self.fullname

        return f"{self.dir}/{self.fullname}"

    def read(self):
        with open(self.path) as f:
            return f.read()

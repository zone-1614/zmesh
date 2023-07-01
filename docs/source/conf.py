# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'ZMesh'
copyright = '2023, zone'
author = 'zone'
release = '1.0.0'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ['breathe', 'exhale', 'recommonmark']

breathe_projects = {
    "ZMesh": "./_doxygen/xml"
}
breathe_default_project = "ZMesh"

exhale_args = {
    "containmentFolder": "./api",
    "rootFileName": "api.rst",
    "rootFileTitle": "API文档",
    "doxygenStripFromPath": "../../include",
    "createTreeView": True,
    "exhaleExecutesDoxygen": True,
    "exhaleDoxygenStdin": "INPUT = ../../include"
}

primary_domain = "cpp"
highlight_language = "cpp"

templates_path = ['_templates']
exclude_patterns = []

language = 'zh_CN'

source_suffix = {
    ".rst": "restructuredtext",
    ".md": "markdown"
}

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']

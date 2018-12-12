# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	wxPython
PORTVERSION=	2.8.12.1
DISTVERSIONPREFIX=	src-
PORTREVISION?=	11
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/wxpython/wxPython/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	28

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings for the wxWidgets/GTK GUI toolkit

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR}

WRKSRC_SUBDIR=	wxPython

DIST_SUBDIR=	python
USE_PYTHON=	distutils
USES=		gettext gmake pkgconfig python:2.7 shebangfix tar:bzip2
SHEBANG_FILES=	wx/tools/Editra/Editra.pyw

PYDISTUTILS_BUILDARGS=	\
			WX_CONFIG="${WX_CONFIG}" \
			WXPORT="${WXPORT}"
PYDISTUTILS_CONFIGUREARGS=	${PYDISTUTILS_BUILDARGS}
PYDISTUTILS_EGGINFODIR=	${PYTHONPREFIX_SITELIBDIR}/${WX_PYTHON_DIR}
USE_WX=		2.8
WX_COMPS=	contrib
WX_PREMK=	yes
DEMO_DIR=	${PYTHONPREFIX_SITELIBDIR}/wxPython/demo
WXPORT=		gtk2

CONFIGURE_ARGS+=	--enable-aui

post-extract:
# only keep the scripts we need
	@${RM} ${WRKSRC}/scripts/*.py

post-patch:
# fix python location
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/scripts/*
	@${RM} ${WRKSRC}/scripts/*.bak

pre-configure:
# uphold PREFIX
	@${REINPLACE_CMD} -E \
		-e "s|([[:space:]]*WXPREFIX[[:space:]]*=).*$$|\1'${PREFIX}'|" \
		${CONFIGURE_WRKSRC}/config.py

post-build:
# Shared amongst ansi/unicode installations
.if defined(WITH_COMMON_ONLY)
. for dir in demo
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/${dir}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/${dir}
. endfor
.endif
.if !defined(DEBUG_FLAGS)
	@${FIND} ${WRKSRC} -name "*.so" | ${XARGS} ${STRIP_CMD}
.endif

.include <bsd.port.pre.mk>

PLIST_SUB+=	WX_VERSION=${USE_WX}

.if defined(WITH_COMMON_ONLY)
## These are not shared amongst installations
PKGNAMESUFFIX=	28-common

PYDISTUTILS_BUILDARGS+=	\
			INSTALL_MULTIVERSION=1
.else
## These are shared
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}wxPython28-common>0:x11-toolkits/py-wxPython28-common@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/wxversion.py:x11-toolkits/py-wxPython-common@${PY_FLAVOR}

PYDISTUTILS_BUILDARGS+=	\
			NO_HEADERS=1 \
			NO_SCRIPTS=1 \
			INSTALL_MULTIVERSION=1

PYDISTUTILS_BUILDARGS+=	\
			UNICODE=1
WX_PYTHON_DIR=	wx-${WX_VERSION}-${WXPORT}-unicode

# plist substitutions
PLIST_SUB+=	WX_PYTHON_DIR=${WX_PYTHON_DIR}

.endif # !defined(WITH_COMMON_ONLY)

# install arguments
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS} ${PYDISTUTILS_BUILDARGS}

## Shared amongst ansi/unicode installations
# XXX - Override do-install since I was not able to tell setup.py to
# do the right thing
.if defined(WITH_COMMON_ONLY)
do-install:
# DEMO
	@${MKDIR} ${STAGEDIR}${DEMO_DIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${DEMO_DIR}
# header files
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/wx-${WX_VERSION}/wx/wxPython/i_files
.for glob in *.i *.py
	${INSTALL_DATA} ${WRKSRC}/src/${glob} \
		${STAGEDIR}${PREFIX}/include/wx-${WX_VERSION}/wx/wxPython/i_files
.endfor
	${INSTALL_DATA} ${WRKSRC}/include/wx/wxPython/*.h \
		${STAGEDIR}${PREFIX}/include/wx-${WX_VERSION}/wx/wxPython
# scripts
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/bin
.endif # defined(WITH_COMMON_ONLY)

post-install:
.if !defined(WITH_COMMON_ONLY)
	@${ECHO_CMD} "@unexec ${REINPLACE_CMD} -i '' -e '\,${WX_PYTHON_DIR}$$,d' ${PYTHON_SITELIBDIR}/wx.pth 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo ${WX_PYTHON_DIR} >> ${PYTHON_SITELIBDIR}/wx.pth 2>/dev/null || true" >> ${TMPPLIST}
# fix installation permissions
	${CHMOD} -R a+rX \
		${STAGEDIR}${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/${WX_PYTHON_DIR}
# Remove unwanted .egg-info
	${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/wxPython_common-*.egg-info
	${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/wx.pth
	${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/wxversion*
	${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/${WX_PYTHON_DIR}/*.egg-info
.endif

.include <bsd.port.post.mk>

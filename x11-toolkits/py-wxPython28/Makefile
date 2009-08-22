# New ports collection makefile for:    wxPython
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxPython
PORTVERSION=	2.8.7.1
PORTREVISION?=	3
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/wxpython/wxPython/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Python bindings for the wxWidgets/GTK GUI toolkit

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

WRKSRC=		${WRKDIR}/${DISTNAME}/wxPython

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PLIST_SUB=	PYTHON_VER=${PYTHON_VER}

PYDISTUTILS_BUILDARGS=	\
			WX_CONFIG="${WX_CONFIG}" \
			WXPORT="${WXPORT}"
PYDISTUTILS_CONFIGUREARGS=	${PYDISTUTILS_BUILDARGS}
PYDISTUTILS_NOEGGINFO=	yes
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
. for dir in demo wxversion
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/${dir}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/${dir}
. endfor
.endif
.if !defined(DEBUG_FLAGS)
	@${FIND} ${WRKSRC} -name "*.so" | ${XARGS} ${STRIP_CMD}
.endif

.include <bsd.port.pre.mk>

# wx version
.if exists(${WX_CONFIG})
WX_VERSION!=	${WX_CONFIG} --release
PLIST_SUB+=	WX_VERSION=${WX_VERSION}
.endif

.if defined(WITH_COMMON_ONLY)
## These are not shared amongst installations
PKGNAMESUFFIX=	-common

PYDISTUTILS_BUILDARGS+=	\
			INSTALL_MULTIVERSION=1
.else
## These are shared
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxversion.py:${PORTSDIR}/x11-toolkits/py-wxPython28-common

PYDISTUTILS_BUILDARGS+=	\
			NO_HEADERS=1 \
			NO_SCRIPTS=1 \
			INSTALL_MULTIVERSION=1

. if defined(WITH_WXPYTHON_UNICODE)
WX_UNICODE=	yes

PKGNAMESUFFIX=	-unicode

PYDISTUTILS_BUILDARGS+=	\
			UNICODE=1
WX_PYTHON_DIR=	wx-${WX_VERSION}-${WXPORT}-unicode
. else
PYDISTUTILS_BUILDARGS+=	\
			UNICODE=0
WX_PYTHON_DIR=wx-${WX_VERSION}-${WXPORT}-ansi
. endif # defined(WITH_WXPYTHON_UNICODE)

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
	@${MKDIR} ${DEMO_DIR}
	@cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${DEMO_DIR}
# header files
	@${MKDIR} ${PREFIX}/include/wx-${WX_VERSION}/wx/wxPython/i_files
.for glob in *.i *.py
	@${INSTALL_DATA} ${WRKSRC}/src/${glob} \
		${PREFIX}/include/wx-${WX_VERSION}/wx/wxPython/i_files
.endfor
	@${INSTALL_DATA} ${WRKSRC}/include/wx/wxPython/*.h \
		${PREFIX}/include/wx-${WX_VERSION}/wx/wxPython
# scripts
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/bin
## wxversion
	@${MKDIR} ${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}
# wxversion script
	@${INSTALL_DATA} ${WRKSRC}/wxversion/* \
		${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}
.endif # defined(WITH_COMMON_ONLY)

post-install:
.if !defined(WITH_COMMON_ONLY)
# fix installation permissions
	${CHMOD} -R a+rX \
		${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/${WX_PYTHON_DIR}
# Remove unwanted .egg-info
	${RM} ${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/wxPython_common-*.egg-info
.endif
##
# wxversion wxPython available list
##
.if !defined(WITH_COMMON_ONLY)
# add ansi/unicode to the available list
	@${ECHO_CMD} ${WX_PYTHON_DIR} >> \
		${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/wx.pth
	@${CHMOD} ${SHAREMODE} \
		${PYTHON_SITELIBDIR:C@^${LOCALBASE}@${PREFIX}@}/wx.pth
.endif

.include <bsd.port.post.mk>

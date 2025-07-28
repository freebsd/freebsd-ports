PORTNAME=	stumpwm
DISTVERSION=	24.11-2
PORTREVISION=	7
DISTVERSIONSUFFIX=	-gd54bebd
CATEGORIES=	x11-wm lisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Tiling, keyboard driven Window Manager written in Common Lisp
WWW=		https://www.nongnu.org/stumpwm/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cl-alexandria-sbcl>=0:devel/cl-alexandria-sbcl \
		cl-alexandria>=0:devel/cl-alexandria \
		cl-clx-sbcl>=0:x11/cl-clx-sbcl \
		cl-clx>=0:x11/cl-clx \
		cl-ppcre-sbcl>=0:textproc/cl-ppcre-sbcl \
		cl-ppcre>=0:textproc/cl-ppcre \
		sbcl:lang/sbcl \
		texinfo>=0:print/texinfo
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		autoreconf gmake
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-compression \
		--with-module-dir=${DATADIR}/modules

MAKE_ARGS=	destdir=${STAGEDIR}
MAKE_JOBS_UNSAFE=	yes

INFO=		${PORTNAME}
PLIST_FILES=	bin/stumpwm
PORTDOCS=	AUTHORS COPYING HACKING NEWS README.md
PORTEXAMPLES=	sample-stumpwmrc.lisp

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>

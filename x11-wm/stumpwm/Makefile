PORTNAME=	stumpwm
DISTVERSION=	23.11
CATEGORIES=	x11-wm lisp
MASTER_SITES+=	https://beta.quicklisp.org/archive/alexandria/2023-10-21/:alexandria \
		https://beta.quicklisp.org/archive/cl-ppcre/2023-06-18/:ppcre \
		https://beta.quicklisp.org/archive/clx/2023-06-18/:clx
DISTFILES+=	alexandria-20231021-git.tgz:alexandria \
		cl-ppcre-20230618-git.tgz:ppcre \
		clx-20230618-git.tgz:clx

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Tiling, keyboard driven Window Manager written in Common Lisp
WWW=		https://www.nongnu.org/stumpwm/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sbcl:lang/sbcl \
		texinfo>=0:print/texinfo

USES=		autoreconf gmake
USE_GITHUB=	yes
USE_SBCL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-compression \
		--with-module-dir=${DATADIR}/modules

MAKE_ARGS=	destdir=${STAGEDIR}

INFO=		${PORTNAME}
PLIST_FILES=	bin/stumpwm
PORTDOCS=	AUTHORS COPYING HACKING NEWS README.md
PORTEXAMPLES=	sample-stumpwmrc.lisp

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	${FIND} ${WRKDIR} -type f -name \*.asd -a \! -name stumpwm\*.asd \
		\! -name dynamic-mixins-swm.asd -exec ${LN} -s {} ${WRKSRC} \;

do-build:
	(cd ${WRKSRC} && \
		ASDF_OUTPUT_TRANSLATIONS="/:" \
		sbcl \
		--noinform --non-interactive --no-sysinit --no-userinit \
		--eval "(require :uiop)" \
		--eval "(setf sb-impl::*default-external-format* :UTF-8)" \
		--load ./make-image.lisp)

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>

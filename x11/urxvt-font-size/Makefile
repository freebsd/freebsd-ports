PORTNAME=	urxvt-font-size
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3
CATEGORIES=	x11

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Perl extension for rxvt-unicode terminal emulator to change font size

LICENSE=	MIT

RUN_DEPENDS=	urxvt:x11/rxvt-unicode

NO_ARCH=	yes
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	majutsushi
OPTIONS_DEFINE=	DOCS
PORTDOCS=	README

INSTDIR_REL=	lib/urxvt/perl
SCRIPTS=	font-size
PLIST_FILES=	${LOCALBASE}/${INSTDIR_REL}/font-size
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR_REL}
	${INSTALL_DATA} ${WRKSRC}/font-size ${STAGEDIR}${PREFIX}/${INSTDIR_REL}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>

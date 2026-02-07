PORTNAME=	urxvt-font-size
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Perl extension for rxvt-unicode terminal emulator to change font size
WWW=		https://github.com/majutsushi/urxvt-font-size

LICENSE=	MIT

RUN_DEPENDS=	urxvt:x11/rxvt-unicode \
		xlsfonts:x11-fonts/xlsfonts

USE_GITHUB=	yes
GH_ACCOUNT=	majutsushi

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	${LOCALBASE}/${_INSTDIR_REL}/font-size
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

_INSTDIR_REL=	lib/urxvt/perl

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${_INSTDIR_REL}
	${INSTALL_DATA} ${WRKSRC}/font-size \
		${STAGEDIR}${PREFIX}/${_INSTDIR_REL}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown \
		${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>

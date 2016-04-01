# $FreeBSD$

PORTNAME=	urxvt-perls
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Perl extension scripts for rxvt-unicode terminal emulator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/urxvt:x11/rxvt-unicode

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	muennich
PORTDOCS=	README

INSTDIR_REL=	lib/urxvt/perl
SCRIPTS=	clipboard keyboard-select url-select
PLIST_FILES+=	${SCRIPTS:C/^/${INSTDIR_REL}\//}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR_REL}
.for s in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/${s} ${STAGEDIR}${PREFIX}/${INSTDIR_REL}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>

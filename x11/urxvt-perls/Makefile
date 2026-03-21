PORTNAME=	urxvt-perls
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Perl extension scripts for rxvt-unicode terminal emulator
WWW=		https://github.com/xyb3rt/urxvt-perls

DEPRECATED=	Upstream repository archived in 2021
EXPIRATION_DATE=	2026-05-04

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/urxvt:x11/rxvt-unicode

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	muennich
PORTDOCS=	README

INSTDIR_REL=	lib/urxvt/perl
SCRIPTS=	clipboard keyboard-select url-select
PLIST_FILES+=	${SCRIPTS:C/^/${INSTDIR_REL}\//}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR_REL}
.for s in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/${s} ${STAGEDIR}${PREFIX}/${INSTDIR_REL}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>

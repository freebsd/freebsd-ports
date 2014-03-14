# $FreeBSD$

PORTNAME=	urxvt-perls
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Perl extension scripts for rxvt-unicode terminal emulator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/urxvt:${PORTSDIR}/x11/rxvt-unicode

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	muennich
GH_COMMIT=	dd6e9d7

INSTDIR_REL=	lib/urxvt/perl
SCRIPTS=	clipboard keyboard-select url-select
PLIST_FILES+=	${SCRIPTS:C/^/${INSTDIR_REL}\//}
PLIST_DIRSTRY+=	${INSTDIR_REL}
.if !defined(NOPORTDOCS)
PLIST_FILES+=	${DOCSDIR_REL}/README
PLIST_DIRS+=	${DOCSDIR_REL}
.endif

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/${INSTDIR_REL}
.for s in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/${s} ${PREFIX}/${INSTDIR_REL}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}/README
.endif

.include <bsd.port.mk>

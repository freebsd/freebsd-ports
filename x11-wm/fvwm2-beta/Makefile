# New ports collection makefile for:	Fvwm2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	fvwm
PORTVERSION=	2.3.19
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		fvwm_icons.tgz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	Cy.Schubert@uumail.gov.bc.ca

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB=	VER=${PORTVERSION}

MAN1=	FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 \
	FvwmCpp.1 FvwmEvent.1 FvwmForm.1 FvwmIconMan.1 \
	FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmRearrange.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScroll.1 \
	fvwm2.1 xpmroot.1 FvwmAnimate.1 FvwmAuto.1 \
	FvwmIconBox.1 FvwmWinList.1

post-extract:
	@if ! (cd ${WRKDIR}/${DISTNAME} && ${MKDIR} icons && cd icons && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/fvwm_icons.tgz ${EXTRACT_AFTER_ARGS}); then \
		exit 1; \
	fi

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm \
		${PREFIX}/lib/X11/fvwm2/pixmaps
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

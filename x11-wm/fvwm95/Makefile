# New ports collection makefile for:	fvwm95-2
# Date created:		Sa   1 Feb 1997 14:46:05 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	fvwm95
PORTVERSION=	2.0.43a
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-Autoconf
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Win95 lookalike version of the fvwm2 window manager

DEPRECATED=	Depends on x11/fbsd-icons, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

LIB_DEPENDS=	rplay.1:${PORTSDIR}/audio/rplay
RUN_DEPENDS=	${LOCALBASE}/icons/chuck.xpm:${PORTSDIR}/x11/fbsd-icons

USE_XORG=	xbitmaps x11 xpm xmu xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib

.ifndef(NO_INSTALL_MANPAGES)
MAN1=		fvwm95.1 FvwmAudio.1 FvwmDebug.1 FvwmSave.1 FvwmAuto.1 FvwmForm.1 \
		FvwmSaveDesk.1 FvwmBacker.1 FvwmIconBox.1 FvwmScroll.1 \
		FvwmBanner.1 FvwmIconMan.1 FvwmTalk.1 FvwmButtons.1 FvwmIdent.1 \
		FvwmTaskBar.1 FvwmConsole.1 FvwmM4.1 FvwmWinList.1 FvwmCpp.1 \
		FvwmPager.1

post-install:
	@${INSTALL_MAN}	${WRKSRC}/fvwm/fvwm95.man \
		${PREFIX}/man/man1/fvwm95.1
	for na in ${WRKSRC}/modules/Fvwm*/*.man; do \
		name=$$(basename $$na .man).1; \
		${INSTALL_MAN} $$na ${PREFIX}/man/man1/$$name; \
	done
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	xkbset
# Date created:		12 May 2001
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=		xkbset
PORTVERSION=		0.5
CATEGORIES=		x11
MASTER_SITES=		http://www.math.missouri.edu/~stephen/software/xkbset/

MAINTAINER=		stephen@math.missouri.edu

MAN1=			xkbset.1
USE_X_PREFIX=		yes
USE_REINPLACE=		yes
USE_PERL5_BUILD=	yes

# xkbset-gui needs p5-Tk, but we do not want to force such a heavy
# dependency for an optional component.
#
#RUN_DEPENDS=		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

MAKE_ARGS=		X11BASE="${X11BASE}" X11PREFIX="${PREFIX}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-build:
	${REINPLACE_CMD} "s%#!/usr/bin/perl%#!${PERL}%" ${WRKSRC}/xkbset-gui

.include <bsd.port.mk>

# New ports collection makefile for:	uwm
# Date created:				2000-10-16
# Whom:					trevor
#
# based on the NetBSD package
# $NetBSD: Makefile,v 1.2 2000/02/02 08:07:07 itohy Exp $
# $FreeBSD$
#

PORTNAME=	uwm
PORTVERSION=	19881027
CATEGORIES=	x11
MASTER_SITES=	\
	ftp://ftp.netbsd.org/pub${SUB} \
	ftp://ftp.netbsd.org/pub${SUB2} \
	ftp://ftp.planix.com/pub${SUB} \
	ftp://ftp.planix.com/pub${SUB2} \
	ftp://ftp.plig.net/pub${SUB} \
	ftp://ftp.plig.net/pub${SUB2} \
	ftp://ftp.csua.berkeley.edu/pub/.1/ports/distfiles/ \
	ftp://ftp.iastate.edu/pub/netbsd/packages/distfiles/ \
	ftp://ftp.iastate.edu/pub/netbsd/packages/distfiles/LOCAL_PORTS/ \
	ftp://sunsite.cnlab-switch.ch/mirror${SUB} \
	ftp://ftp.unina.it/pub/Unix${SUB} \
	ftp://ftp.unina.it/pub/Unix${SUB2} \
	ftp://ftp.sunsite.org.uk/Mirrors/ftp.netbsd.org/pub${SUB} \
	ftp://ftp.sunsite.org.uk/Mirrors/ftp.netbsd.org/pub${SUB2} \
	ftp://ftp.dti.ad.jp/pub${SUB} \
	ftp://ftp.dti.ad.jp/pub${SUB2} \
	ftp://ftp.jaist.ac.jp/.arc07${SUB} \
	ftp://ftp.jaist.ac.jp/.arc07${SUB2} \
	ftp://ftp.tokyonet.ad.jp${SUB} \
	ftp://ftp.sra.co.jp/pub/os${SUB} \
	ftp://ftp.sra.co.jp/pub/os${SUB2} \
	ftp://ftp.nectec.or.th/pub/bsd-distributions${SUB}
SUB=	/NetBSD/packages/distfiles/
SUB2=	${SUB}LOCAL_PORTS/
DISTNAME=	X.V11R3uwm

MAINTAINER=	trevor@FreeBSD.org

MAN1=			uwm.1
USE_IMAKE=		yes
WRKSRC=			${WRKDIR}/X.V11R3/clients/uwm
XFREE86_HTML_MAN=	no	# HTML had not yet been invented.

post-patch:
	${PERL} -pi -e 's:/usr/lib/X11:${PREFIX}/lib/X11:g' ${WRKSRC}/uwm.man

post-install:
	${MKDIR} ${PREFIX}/lib/X11/uwm
	${INSTALL_DATA} ${WRKSRC}/default.uwmrc \
		${PREFIX}/lib/X11/uwm/system.uwmrc

.include <bsd.port.mk>

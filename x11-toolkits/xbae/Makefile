# New ports collection makefile for:	Xbae
# Date created:		11 December 96
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
# With some
# modifications from:	Andreas Klemm <andreas@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	xbae
PORTVERSION=	4.9.1
CATEGORIES=	x11-toolkits math
MASTER_SITES=	ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/lesstif/srcdist/
MASTER_SITE_SUBDIR=	widgets/motif
DISTNAME=	Xbae-${PORTVERSION}

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de

USE_MOTIF=	yes
USE_IMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

HAS_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix=${X11BASE} --enable-xbae-24bit --enable-xbae-row-heights

MAN3=		XbaeCaption.3 XbaeInput.3 XbaeMatrix.3

.include <bsd.port.pre.mk>

post-patch:
	for na in $$(find ${WRKSRC}/examples -name Makefile.in); do \
	  ${CP} $$na $$na.orig; \
	  ${SED} "s%-lXm%${MOTIFLIB}%" $$na.orig > $$na; \
	done

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libXbae.so.8.4 ${PREFIX}/lib/libXbae.so
.endif
	${RM} -rf ${PREFIX}/include/Xbae
	${LN} -sf Xbae-4.8 ${PREFIX}/include/Xbae
	${INSTALL_DATA} ${WRKSRC}/include/Xbae/patchlevel.h ${PREFIX}/include/Xbae

.include <bsd.port.post.mk>
